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

//Joystick control parameters

int vertJoy = A0;
int horzJoy = A1;

//Motor Speed Values at Start

int motorSpeed1 = 0;
int motorSpeed2 = 0;

//Joystick parameters.Middle position(512) at start

int vertJoypos = 512;
int horzJoypos = 512;

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Motors disable and forward direction at start

  //Motor - 1

  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  //Motor - 2

  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
}

void loop() 
{
  //Reading Joystick's X and Y positions

  vertJoypos = analogRead(vertJoy);
  horzJoypos= analogRead(horzJoy);

  //Apply returns to motor speeds and directions

  if (vertJoypos < 475)
  {
    //That mean is backward position

    //Setting Motor - 1

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    //Setting Motor - 2

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    //Determine motor speeds

    //As we are going backwards that' why we need to reserve readings

    vertJoypos = vertJoypos - 475;  //Produce a negative number
    vertJoypos = vertJoypos * (-1); //make the number positive again

    motorSpeed1 = map(vertJoypos, 0, 475, 0, 255);
    motorSpeed2 = map(vertJoypos, 0, 475, 0, 255);
  }
  else if (vertJoypos > 549) //512-475+512=549
  {
    //That mean is forward position

    //Setting Motor - 1

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //Setting Motor - 2

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    //Determine motor speeds

    motorSpeed1 = map(vertJoypos, 549, 1023, 0, 255);
    motorSpeed2 = map(vertJoypos, 549, 1023, 0, 255);
  }
  else
  {
    //That mean is stop position

    motorSpeed1 = 0;
    motorSpeed2 = 0;
  }

  // Now do the steering
  // The Horizontal position will "weigh" the motor speed
  // Values for each motor

  if (horzJoypos < 475)
  {
    //That mean is move to left
    
    //As we are going Left that' why we need to reserve readings

    horzJoypos = horzJoypos - 475;  //Produce a negative number
    horzJoypos = horzJoypos * (-1); //make the number positive again

    horzJoypos = map(horzJoypos, 0, 475, 0, 255);

    motorSpeed1 = motorSpeed1 - horzJoypos;
    motorSpeed2 = motorSpeed2 + horzJoypos;

    if (motorSpeed1 < 0)
      motorSpeed1 = 0;
    if (motorSpeed2 > 255)
      motorSpeed2 = 255;
  }
  else if (horzJoypos > 549)
  {
    //That mean is move to right

    horzJoypos = map(horzJoypos, 549, 1023, 0, 255);

    motorSpeed1 = motorSpeed1 + horzJoypos;
    motorSpeed2 = motorSpeed2 - horzJoypos;
    if (motorSpeed1 > 255)
      motorSpeed1 = 255;
    if (motorSpeed2 < 0)
      motorSpeed2 = 0;
  }

  //Buzzing at very low speed
  if (motorSpeed1 < 10)
    motorSpeed1 = 0;
  if (motorSpeed2 < 10)
    motorSpeed2 = 0;

    analogWrite(enA, motorSpeed1);
    analogWrite(enB, motorSpeed2);
}
