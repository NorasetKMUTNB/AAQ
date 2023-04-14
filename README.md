# AAQ or Alert Air Quality
## Description
Alert Air Quality is mini-project for 010123120 Embedded System Design Lab Sec2 - KMUTNB

Alert Air Quality is intended to provide notification of PM2.5 dust in the air at the location. By alerting via **LINE Application**, which is an application that most people use regularly And it is convenient to access notifications. and also studying the air quality from various values to see how it relates to the PM2.5 dust value, where the values studied are humidity, temperature and light values, which these values have been studied through the programs that have been used Made in [Software Development Practice II course](https://github.com/NorasetKMUTNB/ts_scraping). 

Alert Air Quality project, Kidbright ESP32 is used as the main board used in this project. Its main function is to connect to the sensor, send the values obtained from the sensor via MQTT to the ThingSpeak website, and be notified via Line Notify when the PM2.5 dust value is exceeded.

## Hardware
* Kidbright ESP32
* SPS30 Sensirion PM2.5 PARTICLE SENSOR
* DHT22 Temperature and Humidity Sensor Module

## Library for Sensor
* [SPS30 Sensirion PM2.5 PARTICLE SENSOR](https://github.com/adafruit/Adafruit_Sensor)
* [DHT22 Temperature and Humidity Sensor Module](https://github.com/adafruit/DHT-sensor-library)

## Datasheet
* [Schematic KidBright ESP32](https://kidbright.info/files/Sch_KidBright32%20V1.3.pdf)
* [SPS30 Sensirion PM2.5 PARTICLE SENSOR](https://cdn-shop.adafruit.com/datasheets/Digital+humidity+and+temperature+sensor+AM2302.pdf)
* [DHT22 Temperature and Humidity Sensor Module](https://cdn.sparkfun.com/assets/2/d/2/a/6/Sensirion_SPS30_Particulate_Matter_Sensor_v0.9_D1__1_.pdf)
