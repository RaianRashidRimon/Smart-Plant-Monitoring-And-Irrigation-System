#define BLYNK_TEMPLATE_ID "PASTE YOUR BLIYNK TEMPLATE ID HERE"
#define BLYNK_TEMPLATE_NAME "PASTE YOUR TEMPLATE NAME HERE"
#define BLYNK_AUTH_TOKEN "PASTE YOUR AUTHENTICATION TOKEN HERE"

#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = " Paste your authenticatiion token here";
char ssid[] = "Name of the network your NODE MCU is connected to";
char pass[] = "Password to connect to that network";
BlynkTimer timer;
bool Relay = 0;
#define sensor A0
#define waterPump D3

void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, HIGH);
  lcd.init();
  lcd.backlight();
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  lcd.setCursor(1, 0);
  lcd.print("System Loading");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
  timer.setInterval(100L, soilMoistureSensor);
}

BLYNK_WRITE(V1) {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(waterPump, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  } else {
    digitalWrite(waterPump, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF");
  }
}

void soilMoistureSensor() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V0, value);
  lcd.setCursor(0, 0);
  lcd.print("Moisture :");
  lcd.print(value);
  lcd.print(" ");
}
void loop() {
  Blynk.run();
  timer.run();
}
