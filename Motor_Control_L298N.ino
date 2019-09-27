/*  
 * L298N Motor Demonstration
 * L298N_Motor.ino
 * Demonstrates functions of L298N Motor Controller
 * 
 * Ersel YURDAKUL presents
 * 
 * 27.09.2019
 * Istanbul / Turkey
 */


//  Motor - 1

int enA = 3;
int in1 = 4;
int in2 = 5;

//  Motor - 2

int enB = 9;
int in3 = 7;
int in4 = 8;

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void motorDemonOne()
{
  //This fuction will run the motors in both di,rections at a fixed speed.

  //Turn on Motor - 1

   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);

  //Set speed to 200 out of possible range 0 - 255
   analogWrite(enA, 200);

  //Turn on Motor - 2

  digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);

  //Set speed to 200 out of possible range 0 - 255
   analogWrite(enB, 200);

   delay(15000);

  //Change motor directions

   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);

   delay(15000);

  //Turn off Motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}

void motorDemonTwo()
{
  //This Function will run the motors across the range of possible speeds.
  //Note that max speed is determined by motor itself and the operating voltage.

  //Turn on Motors

  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);

  //Accelerate from zero to max speed

  for(int i = 0; i < 256; ++i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);

    delay(10);
  }

  //Decelerate from max speed to zero

  for(int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);

    delay(10);
  }

  //Turn off the Motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() 
{
  motorDemonOne();
  delay(300);
  motorDemonTwo();
  delay(300);
}
