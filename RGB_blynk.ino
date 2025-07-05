#define BLYNK_TEMPLATE_ID "TMPL3icIS9CYW"
#define BLYNK_TEMPLATE_NAME "RGB BLYNK"
#define BLYNK_AUTH_TOKEN "AB00HjiaohpBHmeJTE3LMxGh8LhYDGku"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "GalaxyA";
char pass[] = "xyeb0000";

const int redPin = 25;
const int greenPin = 26;
const int bluePin = 27;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
  int r = param.asInt();
  analogWrite(redPin, r);
}

BLYNK_WRITE(V2)
{
  int g = param.asInt();
  analogWrite(greenPin, g);
}

BLYNK_WRITE(V3)
{
  int b = param.asInt();
  analogWrite(bluePin, b);
}