// By : Rati Kaewkam
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin = 7;
const int echoPin = 8;

long duration, distance;

// Set the LCD address
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ready...");
  delay(1000);
  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) * 0.343;
  
  lcd.print((String)distance + " cm");
  delay(500);
  lcd.clear();
}
