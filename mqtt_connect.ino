// Connecting WIFI
void connect_wifi(){
  // Check if WiFi is connected
  if (WiFi.status() != WL_CONNECTED) {
    //Connect to Router
    Serial.print("Connecting to :");
    Serial.print(ssid);
    Serial.print(" : ");
    //Connect ESP32 to home network
    WiFi.begin(ssid, pass);
    //Wait until Connection is complete
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    // Serial.println("\nConnected.");
  }
}

// Connect MQTT Server
void mqtt_server(){
  //Check if MQTT Server is connected
  if (!mqtt.connected()) {
    Serial.println("Connecting to MQTT Broker.");
    mqtt.connect(clientID, mqttUserName, mqttPass);
    while (!mqtt.connected()) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nConnected MQTT Broker.");
  }
}