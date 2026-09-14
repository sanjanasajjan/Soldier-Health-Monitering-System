#include <LiquidCrystal.h>

#define LM35_PIN A1
#define PULSE_PIN A0
#define BUZZER 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

void setup() {
  lcd.begin(16, 2);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Soldier Health");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring Sys");
  delay(2000);
  lcd.clear();
}

void loop() {
  int lm35Value = analogRead(LM35_PIN);
  float voltage = lm35Value * (5.0 / 1023.0);
  float temperature = voltage * 100; // LM35: 10mV per °C

  int pulseValue = analogRead(PULSE_PIN);

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("Pulse:");
  lcd.print(pulseValue);
  lcd.print("  ");

  if (temperature == 37 || pulseValue == 100) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(1000);
}
