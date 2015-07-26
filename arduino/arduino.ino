#include "Ultrasonic.h"

int enA = 10;
int enB = 9;
int inA1 = 5;
int inA2 = 4;
int inB1 = 3;
int inB2 = 2;
Ultrasonic uLeft(6, 7);
Ultrasonic uRight(12, 13);

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);
  reset();
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int t=1000;
  float val = 30.0;
  
  float dLeft = (uLeft.Ranging(1)+uLeft.Ranging(1)+uLeft.Ranging(1))/3;
  float dRight = (uRight.Ranging(1)+uRight.Ranging(1)+uRight.Ranging(1))/3; 

  if(dLeft < val && dRight < val)
  {
    back(1000);
    turnRight(2000);
  }
  else if(dLeft < val && dRight > val)
  {
    turnRight(1);
  }
  else if(dLeft > val && dRight < val)
  {
    turnLeft(1);
  }
  else if(dLeft > val && dRight > val)
  {
    forward(1);
  }
  
  //Serial.print("Left \t");
  //Serial.print(dLeft);
  //Serial.print("\tRight\t");
  //Serial.print(dRight);
  //Serial.print("\n");
  
  //pwmMove(75,255,t);
  //forward(t);
  //turnLeft(t);
  //back(t);
  //turnRight(t);
}

void reset()
{
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
}

void forward(int t)
{
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
  delay(t);
  //reset();
}

void back(int t)
{
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  delay(t);
  //reset();
}

void turnLeft(int t)
{
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
  delay(t);
  //reset();
}

void turnRight(int t)
{
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
  delay(t);
  //reset();
}

void pwmMove(int pwmA, int pwmB, int t)
{
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
  analogWrite(enA, pwmA);
  analogWrite(enB, pwmB);
  delay(t);
  //reset();
}

