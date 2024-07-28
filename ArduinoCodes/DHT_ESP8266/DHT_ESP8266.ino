#include <ESP8266WiFi.h>
#include <DHT.h>
const char* ssid = "MOVISTAR-WIFI6-47A8";
const char* password = "WkHnfdkfkYaWndci39nY";
WiFiClient client;
#define DHTPIN 4      // Pin D4 en NodeMCU (equivalente a GPIO 2)
#define DHTTYPE DHT11 // Definición del tipo de sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid,password);
  while(WiFi.status() !=WL_CONNECTED) delay(500);
  
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
    delay(2000);

  // Lee la humedad y la temperatura
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Revisa si alguna lectura falló e imprime un mensaje de error
  if (isnan(h) || isnan(t)) {
    Serial.print("DHT11, \t");
    Serial.println("Failed to read from DHT sensor!");
    return;
 }
     // Imprime los valores leídos
  Serial.print("DHT11, \t");
  Serial.print("OK,\t");
  Serial.print(h);
  Serial.print(",\t");
  Serial.println(t);
}
