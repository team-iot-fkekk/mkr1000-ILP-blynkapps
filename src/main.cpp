/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Arduino MKR1000
  to connect your project to Blynk.

  Note: This requires WiFi101 library
    from http://librarymanager/all#WiFi101

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>
#include <secrets-example.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = SECRET_AUTH_KEY;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

int sensorPin = A0;
int sensorValue = 0;
float temperature = 0.0;
float voltage = 0.0;

BLYNK_READ(V5)
{
  Blynk.virtualWrite(V5, temperature);
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  analogReadResolution(10);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.print("sensorValue = ");
  Serial.print(sensorValue);
  voltage = sensorValue * (3300 / 1024);
  Serial.print("  voltage = ");
  Serial.print(voltage);
  temperature = (voltage - 500) / 10;
  Serial.print("    temperature = ");
  Serial.println(temperature);
  delay(100);
  Blynk.run();
}
