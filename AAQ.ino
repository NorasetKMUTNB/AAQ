#include "data/mqtt_secrets.h"
#include "data/secret_key.h"

#include <HTTPClient.h>
#include <PubSubClient.h>

// replace with your wifi ssid and wpa2 key
const char *ssid = WIFI_ID;
const char *pass = WIFI_PASSWORD;

const char *server = "mqtt3.thingspeak.com";
const char *channelID = CHANNEL_ID;
const char *mqttUserName = SECRET_MQTT_USERNAME;
const char *mqttPass = SECRET_MQTT_PASSWORD;
const char *clientID = SECRET_MQTT_CLIENT_ID;

WiFiClient client;
PubSubClient mqtt(client);

// Line Notify
#include <WiFi.h>
#include <Wire.h>
#include <TridentTD_LineNotify.h>

// bool notify_state = 0;
bool dht_state = 1;
bool sps_state = 1;

// Light
#define LED_IOT 12
#define LDR_Pin 36

// DHT22
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// SPS30
#include "sps30.h"
#define SP30_COMMS Serial1
#define DEBUG 0
SPS30 sps30;

String server_req = "api.thingspeak.com";

// =======================================================
void setup()
{

  pinMode(LED_IOT, OUTPUT);
  pinMode(LDR_Pin, INPUT);

  // DH22
  dht.begin();
  // SPS30
  connect_sps30();

  // mqtt
  mqtt.setServer(server, 1883);

  LINE.setToken(LINE_TOKEN);

  Serial.begin(115200);
}

// =======================================================

void loop()
{
  unsigned static int second_count = 0;

  // Serial.println("start" + String(second_count));

  uint16_t ligth = analogRead(LDR_Pin);

  // check wifi
  connect_wifi();
  // check mqtt server
  mqtt_server();

  // read DHT22
  float arr_dht[2];
  read_dht(arr_dht);

  float h;
  h = arr_dht[0];
  float t;
  t = arr_dht[1];

  // read SPS30
  float pm;
  pm = read_sps();

  // Is connect yet?

  // Check Disconnect Device
  check_device();

  // Post http get to ThingSpeak Every 15 seconds
  if (second_count >= 15)
  {
    // Reset Timer
    second_count = 0;

    String dataString = "&field1=" + String(ligth) // Field1 = Ligth Value
                        + "&field2=" + String(t)   // Field2 = Temperature
                        + "&field3=" + String(h)   // Field3 = Humidity
                        + "&field4=" + String(pm); // Field4 = PM2.5

    // Channels
    String topicString = "channels/" + String(channelID) + "/publish";
    mqtt.publish(topicString.c_str(), dataString.c_str());

    // Serial Monitor
    Serial.println("Ligth Value = " + String(ligth));
    Serial.println("Temperature = " + String(t));
    Serial.println("Humidity    = " + String(h));
    Serial.println("PM2.5       = " + String(pm));
    digitalWrite(LED_IOT, !digitalRead(LED_IOT));

    // Line Notify
    notify(pm);
  }
  // Update seconds every 1000 ms
  delay(1000);
  // Serial.println("end"+ String(second_count));
  second_count++;
}