#include <Arduino.h>
#include <SimpleDHT.h>

#define pinDHT 7 // SD3 pin signal sensor DHT
#define RED_PIN D2
#define GREEN_PIN D5
#define BLUE_PIN D6

byte temperature = 0;
byte humidity = 0;

SimpleDHT11 dht11(D1); // instan sensor dht11

void KelembabanSuhu()
{
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Pembacaan DHT11 gagal, err=");
    Serial.println(err);
    delay(1000);
    return;
  }

  Serial.print("Sample OK: ");
  Serial.print((int)temperature);

  Serial.print(" *C, ");
  Serial.print((int)humidity);
  Serial.println(" H");

  // Set the color of the RGB LED based on the temperature value
  if (temperature < 20)
  {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  }
  else if (temperature >= 20 && temperature < 35)
  {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  }
  else
  {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  }

  delay(1500);
}

// buat kelvin sama reamur

// float kelvin = temperature + 273.15;

// Serial.print("Sample OK: ");
// Serial.print((int)kelvin);

// Serial.print(" *K, ");
// Serial.print((int)humidity);
// Serial.println(" H");

// float reamur = temperature * 0.8;

// Serial.print("Sample OK: ");
// Serial.print((int)reamur);

// Serial.print(" *R, ");
// Serial.print((int)humidity);
// Serial.println(" H");

// Serial.println("");

void setup()
{

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(115200);
  Serial.println("Simple DHT");
  delay(1000);
}

void loop()
{
  KelembabanSuhu();
}