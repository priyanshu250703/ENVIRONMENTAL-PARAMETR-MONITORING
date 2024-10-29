#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define BLYNK_TEMPLATE_ID "TMPL3vC9UpR3V"
#define BLYNK_TEMPLATE_NAME "Priyanshu Project"
#define BLYNK_AUTH_TOKEN "bEEpspkgTXZgWX_iQQe2FDlzJtTZ5zZU"
// Replace with your WiFi credentials
char auth[] = "bEEpspkgTXZgWX_iQQe2FDlzJtTZ5zZU";
char ssid[] = "OnePlus 11";
char pass[] = "123456789P";

// Blynk virtual pins
#define VIRTUAL_PIN_TEMPERATURE V1
#define VIRTUAL_PIN_HUMIDITY V2
#define VIRTUAL_PIN_MQ135 V3
#define VIRTUAL_PIN_MQ08 V4
#define VIRTUAL_PIN_MQ07 V5

// Create object for DHT sensor
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Replace with your MQ sensor analog pin connections
const int MQ135_PIN = A0;
const int MQ08_PIN = A0;
const int MQ07_PIN = A0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop() {
  Blynk.run();

  // Read sensor values
  float temperatureValue = dht.readTemperature();
  float humidityValue = dht.readHumidity();
  int mq135Value = analogRead(MQ135_PIN);
  int mq08Value = analogRead(MQ08_PIN);
  int mq07Value = analogRead(MQ07_PIN);

  // Print values to serial monitor
  Serial.println("Sensor Values:");
  Serial.print("Temperature: ");
  Serial.println(temperatureValue);
  Serial.print("Humidity: ");
  Serial.println(humidityValue);
  Serial.print("MQ135: ");
  Serial.println(mq135Value);
  Serial.print("MQ08: ");
  Serial.println(mq08Value);
  Serial.print("MQ07: ");
  Serial.println(mq07Value);

  // Send sensor values to Blynk app
  Blynk.virtualWrite(VIRTUAL_PIN_TEMPERATURE, temperatureValue);
  Blynk.virtualWrite(VIRTUAL_PIN_HUMIDITY, humidityValue);
  Blynk.virtualWrite(VIRTUAL_PIN_MQ135, mq135Value);
  Blynk.virtualWrite(VIRTUAL_PIN_MQ08, mq08Value);
  Blynk.virtualWrite(VIRTUAL_PIN_MQ07, mq07Value);

  delay(5000); // Delay for 5 seconds
}