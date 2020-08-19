/*
* Author : Nixon Nelson
* Date : 30-7-2020
*  line follower robot
*  using two ir leds
*  and two tank steer motors
*  
*/
//initialization

#define enableA 5
#define enableB 10
#define Aforward 6
#define Abackward 7
#define Bforward 8
#define Bbackward 9
#define irLed1 11
#define irLed2 12

void setup() {
  // put your setup code here, to run once:
  pinMode(enableA,OUTPUT);
  pinMode(enableB,OUTPUT);
  pinMode(Aforward,OUTPUT);
  pinMode(Bforward,OUTPUT);
  pinMode(Abackward,OUTPUT);
  pinMode(Bbackward,OUTPUT); 
  pinMode(irLed1,INPUT);
  pinMode(irLed2,INPUT);
  
  Serial.begin(9600); 
}

void loop() {
  
  motorDrive(1,1,0,0,0,255);
}
void motorDrive(boolean enblA,boolean enblB,boolean left,boolean right,boolean reverse,unsigned int speed ) {
  //function for motor driver
  /*
   * truth table 3 bits 7 possible combo
   * 111-reverse
   * 011-right reverse
   * 101-left reverse
   * 001-reverse NA
   * 110-forward
   * 010-right
   * 100-left
   * 000-stop
   */
  while(enblA && enblB){
      /*digitalWrite(Aforward,LOW);
      digitalWrite(Bforward,LOW);
      digitalWrite(Abackward,LOW);
      digitalWrite(Bbackward,LOW);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
      */
    if((left && right)== true && reverse != true) //110
    {//forward
      digitalWrite(Aforward,HIGH);
      digitalWrite(Bforward,HIGH);
      digitalWrite(Abackward,LOW);
      digitalWrite(Bbackward,LOW);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
    }
    else if(left && ((right && reverse)== false))//100
    {//rotate left
      digitalWrite(Aforward,HIGH);
      digitalWrite(Bforward,LOW);
      digitalWrite(Abackward,LOW);
      digitalWrite(Bbackward,HIGH);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
    }
    else if(right && ((left && reverse)!=true))//010
    {//rotate right
      digitalWrite(Aforward,LOW);
      digitalWrite(Bforward,HIGH);
      digitalWrite(Abackward,HIGH);
      digitalWrite(Bbackward,LOW);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
    }
    else if(reverse && left && right)//111
    {//backward
      digitalWrite(Aforward,LOW);
      digitalWrite(Bforward,LOW);
      digitalWrite(Abackward,HIGH);
      digitalWrite(Bbackward,HIGH);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
    }
    // effective for reverse manuvering
    else if((reverse && left) && right != true)//101
    {// rotate right //reverse left
      
      digitalWrite(Aforward,HIGH);
      digitalWrite(Bforward,LOW);
      digitalWrite(Abackward,LOW);
      digitalWrite(Bbackward,HIGH);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
    }
    else if((reverse && right) && left!= true)//011
    {// rotate left // reverse right
      
      digitalWrite(Aforward,LOW);
      digitalWrite(Bforward,HIGH);
      digitalWrite(Abackward,HIGH);
      digitalWrite(Bbackward,LOW);
      analogWrite(enableA,speed);
      analogWrite(enableB,speed);
    }
    else  //000
    {//stop
      
      digitalWrite(Aforward,LOW);
      digitalWrite(Bforward,LOW);
      digitalWrite(Abackward,LOW);
      digitalWrite(Bbackward,LOW);
      digitalWrite(enableA,LOW);//refer pin 5 in atmel data sheet gets rid of inconsistency
      digitalWrite(enableB,LOW);
    }
  }
}
