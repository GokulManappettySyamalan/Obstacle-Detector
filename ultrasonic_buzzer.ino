/* Gokul Manappetty Syamalan
   Syracuse University
   
   Obstacle Detector Using Arduino . I have added 7 LEDs 1 LCD 7 1k Resistor and 1 active Buzzer
   if the obstacle is more than 25cm all the LEDs will be in OFF mode which means no obstacles detected within a radius of 25 Cm.
   If an obstacle is detected within 25cm it will show the distance at LCD screen which is connected to Arduino using I2c Protocol
   if the obstacle is less than 5 cm alarm will start beeping which alerts the user that an obstacle is there within a radius of 25Cm.
   
*/
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
const int trig = 11;
const int echo = 12;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
int duration = 0;
int distance = 0;
int buzzer=13;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.setCursor(1, 0);
  lcd.print("Gokul's");
  lcd.setCursor(4, 1);
  lcd.print("Sensor");
  delay(2000);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Distance :");
  lcd.setCursor(12, 0);
  lcd.print(distance);
  delay(100);

  if(distance <=5 || distance ==0)
  {
  digitalWrite(buzzer, HIGH);
  delay(500);
  lcd.setCursor(1,1);
  lcd.print("STOP STOP");
  delay(100);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  
  if ( distance <= 5 )
  {
    digitalWrite(LED1, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
  }
  if ( distance <= 7 )
  {
    digitalWrite(LED2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
  }
  if ( distance <= 10 )
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
  if ( distance <= 15 )
  {
    digitalWrite(LED4, HIGH);
  }
  else
  {
    digitalWrite(LED4, LOW);
  }
  if ( distance <= 17 )
  {
    digitalWrite(LED5, HIGH);
  }
  else
  {
    digitalWrite(LED5, LOW);
  }
  if ( distance <= 20 )
  {
    digitalWrite(LED6, HIGH);
  }
  else
  {
    digitalWrite(LED6, LOW);
  }
  if ( distance <= 25 )
  {
    digitalWrite(LED7, HIGH);
  }
  else
  {
    digitalWrite(LED7, LOW);
  }
}
