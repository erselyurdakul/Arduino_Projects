int xPin = A0; 
int yPin = A1; 
int ledK=2; 
int ledM=3; 
int ledY=4; 
int ledS=5;
 
int xPozisyon = 0;
int yPozisyon = 0;
 
 
void setup() {
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(ledK,OUTPUT); 
pinMode(ledM,OUTPUT); 
pinMode(ledY,OUTPUT); 
pinMode(ledS,OUTPUT);
}
 
void loop() 
{
xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);
  if(xPozisyon<600)
  {
    digitalWrite(ledK,LOW);
  }
  else
  {
    digitalWrite(ledK,HIGH);
  }
  if(xPozisyon>600)
  {
    digitalWrite(ledM,LOW);
  }
  else
  {
    digitalWrite(ledM,HIGH);
  } 
  if(yPozisyon<600)
  {
    digitalWrite(ledY,LOW);
  }
  else
  {
    digitalWrite(ledY,HIGH);
  }
  if(yPozisyon>600)
  {
    digitalWrite(ledS,LOW);
  }
  else
  {
    digitalWrite(ledS,HIGH);
  } 
}
