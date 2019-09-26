#include <Servo.h>
int xPin = A0; 
int yPin = A1; 

Servo motor1; 
 
int xPozisyon = 0;
int yPozisyon = 0;
 
 
void setup() 
{
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  motor1.attach(5);
}
 
void loop() 
{
  xPozisyon = map(analogRead(xPin),0,1023,0,180);
  yPozisyon = map(analogRead(yPin),0,1023,0,180);
  if(xPin == INPUT)
  {
    motor1.write(xPozisyon);
  }
  else
  {
    motor1.write(yPozisyon);
  }
}
