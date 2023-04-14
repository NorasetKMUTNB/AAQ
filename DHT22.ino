
#define DHTPIN 4
#define DHTTYPE DHT22

void read_dht(float arr[]){

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  arr[0] = h;
  arr[1] = t;

  // Serial.print(F("Humidity: "));
  // Serial.print(h);
  // Serial.print(F("%\nTemperature: "));
  // Serial.print(t);
  // Serial.print(F("°C  "));
  // Serial.print(f);
  // Serial.print(F("°F\nHeat index: "));
  // Serial.print(hic);
  // Serial.print(F("°C  "));
  // Serial.print(hif);
  // Serial.print(F("°F\n"));

}

int Check_dht(){
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return false ;
  }else {
    return true;
  }
}

