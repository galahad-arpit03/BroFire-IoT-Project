
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3CT2XbHy-"
#define BLYNK_TEMPLATE_NAME "LedControl"
#define BLYNK_AUTH_TOKEN "n2Uy6XZzeTfeO3Y8tE0yZA26R-a2stgT"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "SISTec TP 225 M1";
char pass[] = "1478523690";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

