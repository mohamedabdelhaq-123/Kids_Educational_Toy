#include <LiquidCrystal.h>
#include <Servo.h>

// Initialize the LCD display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize the IR sensor pins
int irSensorPin1 = 7;
int irSensorPin2 = 8;

// Initialize the servo motors
Servo servo1;
Servo servo2;

void setup() {
  // Set up the LCD display to write the enter text 
  lcd.begin(16, 2);
  lcd.setCursor (7,0);
  lcd.print("HI");
  delay(10000);
  // Set up the servo motors
  servo1.attach(6);
  servo2.attach(9);

  // Set up the IR sensor pins
  pinMode(irSensorPin1, INPUT);
  pinMode(irSensorPin2, INPUT);
  
}

void loop() {
  int irSensorValue1 = digitalRead(irSensorPin1);
  int irSensorValue2 = digitalRead(irSensorPin2);
// -------------------------------------------------------------------------------------------------
  if (irSensorValue1 == HIGH) {
    servo1.write(90);
    lcd.clear();
  }
  else {
    servo1.write(0);
    lcd.setCursor(6,0);
     lcd.print("Arm");
    delay(3000);
  }
//---------------------------------------------------------------------------------------------------
// مسؤل عن تشغيل الحساس بالضوء و يعطى امر للمتور ان يلف 90
  if (irSensorValue2 == HIGH) {
    servo2.write(90);
    lcd.clear();
  }
  else {
    servo2.write(0);
    lcd.setCursor(6,0);
   lcd.print("Leg");
    delay(3000);
  }
  
  delay(1000);
}
