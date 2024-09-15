#include <ESP8266WiFi.h>
#include <DHT.h>
#include <WiFiClientSecure.h>
const char* ssid = "";
const char* password = "";
const char*  server = "ecofloat.space";
WiFiClient client;
WiFiClientSecure client2;
#define DHTPIN 4      // Pin D4 en NodeMCU (equivalente a GPIO 2)
#define DHTTYPE DHT11 // Definición del tipo de sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* test_root_ca= \
"-----BEGIN CERTIFICATE-----\n" \
"MIIFADCCA+igAwIBAgISA7dm+uBgn7n6Amb3VG2BPr0UMA0GCSqGSIb3DQEBCwUA\n" \
"MDMxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQwwCgYDVQQD\n" \
"EwNSMTAwHhcNMjQwODMxMTYxMzMyWhcNMjQxMTI5MTYxMzMxWjAZMRcwFQYDVQQD\n" \
"Ew5lY29mbG9hdC5zcGFjZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB\n" \
"AMNxLBgF/qpPyzbT18dkj3xaQlHGuztGnqkUOXgEbE7VISBRrwCLbb5jBuAQ5xVf\n" \
"gTK9t/Ysr2pWK0kVvYj+jrTCT3KVypZvPS+Rmn0y2xOPlr4fgW3e4gr4AvmthB3L\n" \
"C/fbKREJGKLdBuB3OiGHjXj2t1s45xwom458Pj0P97Nb9XJqecEAmzK7GUkzV3HE\n" \
"cxtz4EPuXTeSbQs91v894nlaZHmw2rVMat60bZ0KbbDqxUCpcxrADwkyKULWtJwP\n" \
"jyoL/Et3UUMuKQocH4NNdSnSv1b34fk4M6qUH5Ee94XfMnFDpNlTRIfnbJbC6gqK\n" \
"slWYjBH4nRtnN0HxcKCSm3ECAwEAAaOCAiYwggIiMA4GA1UdDwEB/wQEAwIFoDAd\n" \
"BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwDAYDVR0TAQH/BAIwADAdBgNV\n" \
"HQ4EFgQUZSVMXWt7QikwzNwwtyBv2pl+kqkwHwYDVR0jBBgwFoAUu7zDR6XkvKnG\n" \
"w6RyDBCNojXhyOgwVwYIKwYBBQUHAQEESzBJMCIGCCsGAQUFBzABhhZodHRwOi8v\n" \
"cjEwLm8ubGVuY3Iub3JnMCMGCCsGAQUFBzAChhdodHRwOi8vcjEwLmkubGVuY3Iu\n" \
"b3JnLzAtBgNVHREEJjAkgg5lY29mbG9hdC5zcGFjZYISd3d3LmVjb2Zsb2F0LnNw\n" \
"YWNlMBMGA1UdIAQMMAowCAYGZ4EMAQIBMIIBBAYKKwYBBAHWeQIEAgSB9QSB8gDw\n" \
"AHcASLDja9qmRzQP5WoC+p0w6xxSActW3SyB2bu/qznYhHMAAAGRqWwmagAABAMA\n" \
"SDBGAiEAmQOKMwLREDrI2PdWOZ0WI1tU28oSLtY/bWw7/oolsVMCIQC8er+cj4vr\n" \
"Id1tetpFq0PbQxCsiU7u4EkS08PQXWz8igB1AN/hVuuqBa+1nA+GcY2owDJOrlbZ\n" \
"bqf1pWoB0cE7vlJcAAABkalsJ2IAAAQDAEYwRAIgaso9+rE5qlK5dey+9TTxZ1NM\n" \
"UTpQc7IIfiUJ7y3XDokCIGePmdNC/+bBIQljfbZ5RPQzzGx+P1vNu/4LYpLR32Rg\n" \
"MA0GCSqGSIb3DQEBCwUAA4IBAQAWmrDInowb3kNTijLglxOuVKYhvhZnGgH7MaXT\n" \
"+Af+qtVRvvLv2zjNaCKeWwEXqmaSbed+xL9MTgNOXAzUTuI+v/Pabl75WMBg9W5/\n" \
"13gPf9w4HyWfv2Cq2oKp/vrN0y0C7uh7hK3uQeEkcMH/dr7LpeHdtQwGJo3y55U0\n" \
"fOolelfItJM9qRXlWZ+ttf4Td854Nn/lzgK4tE9Ikc9fUGQWX3MFj+ZRPoc5fWrw\n" \
"Ob8XzNfBpnxfCgFGz4zi2a8hagt4GDGwSJKdNDwYVI6HM30GdqlALhNHOqZ2l2y3\n" \
"IGIpyH142aE/3hEBiHliobrhRyNBy4cOjqSBRa28/Fo4ojOg\n" \
"-----END CERTIFICATE-----\n";


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFi.begin(ssid,password);
  while(WiFi.status() !=WL_CONNECTED) delay(500);
  

  Serial.println("DHT TEST PROGRAM ");
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  dht.begin();


}

void loop() {
  // put your main code here, to run repeatedly:
    delay(20000);
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



String postData = "temperatura=" + String(t) + "&humedad=" + String(h); 
  X509List cert(test_root_ca);
  client2.setInsecure();
  //client2.setTrustAnchors(&cert);
  //client2.setCertificate(test_client_cert); // for client verification
  //client2.setPrivateKey(test_client_key);	// for client verification
if (!client2.connect(server, 443)) {
  Serial.println("No se pudo realizar la conexión segura");
} else {
  // Make a HTTP POST request:
  client2.println("POST /test_data.php HTTP/1.1");  // Cambia '/ruta/del/api' a la ruta correcta
  client2.println("Host: ecofloat.space");      // Cambia 'www.tuservidor.com' por el servidor real
  client2.println("User-Agent: Arduino/1.0");
  client2.println("Connection: close");
  client2.println("Content-Type: application/x-www-form-urlencoded");
  client2.print("Content-Length: ");
  client2.println(postData.length());
  client2.println(); // Línea en blanco que indica el fin de los headers
  client2.println(postData); // Enviamos los datos de la temperatura y humedad

  // Esperar respuesta del servidor:
  while (client2.connected()) {
    String line = client2.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }

  // Leer la respuesta del servidor:
  while (client2.available()) {
    char c = client2.read();
    Serial.write(c);
  }

  client2.stop();  // Finalizar la conexión
}

   
}
