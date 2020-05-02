int pin1 =18;
int pin2 = 19;
int pin3 = 20;
volatile int state1,state2,state3;
volatile long int ch1, ch2,ch3, timer;
//motor one
int enA=7;
int in1=11;
int in2=10;
//motor two
int enB=6;
int in3=9;
int in4=8;
//motor three
int enAx=4;
int in1x=45;
int in2x=44;
//motor four
int enBx=5;
int in3x=46;
int in4x=12;

int velocity;

void setup()
{
 //initialize serial communication at 9600 bits per second
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  pinMode(pin3,INPUT);
  attachInterrupt(digitalPinToInterrupt(pin1), func, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pin2), func, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pin3), func, CHANGE);
  Serial.begin(9600);
  Serial.println("ONline");
  

  //set up motor control pins to output
  pinMode (enA,OUTPUT);
  pinMode (enB,OUTPUT);
  pinMode (in1,OUTPUT);
  pinMode (in2,OUTPUT);
  pinMode (in3,OUTPUT);
  pinMode (in4,OUTPUT);
  //setup 3,4 motor controll output
  pinMode (enAx,OUTPUT);
  pinMode (enBx,OUTPUT);
  pinMode (in1x,OUTPUT);
  pinMode (in2x,OUTPUT);
  pinMode (in3x,OUTPUT);
 pinMode (in4x,OUTPUT);


} 

void func()  
{
  if(digitalRead(pin1)!=state1) 
  {
    state1 = !state1;
    if(state1 == 1)
      timer = micros();
    else
      ch1 = micros()-timer;
  }
  if(digitalRead(pin2)!=state2)
  {
    state2 = !state2;
    if(state2 == 1)
      timer = micros();
    else
      ch2 = micros()-timer;
  }
  if(digitalRead(pin3)!=state3)
  {
     state3 =!state3;
        if(state3 == 1)
        timer = micros();
        else
        ch3 = micros()-timer;
      }
}

void forward()  {
  digitalWrite (in1,HIGH);
  digitalWrite (in2,LOW);
  digitalWrite (in3,HIGH);
  digitalWrite (in4,LOW);
  
  //turn on motor B
  digitalWrite (in1x,HIGH);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,HIGH);
  digitalWrite (in4x,LOW);

}

void backward() {
  //changing the motor driver in backward direction
  digitalWrite (in1,LOW);
  digitalWrite (in2,HIGH);
  digitalWrite (in3,LOW);
  digitalWrite (in4,HIGH);
  //changing the motor driver B direction in backward direction
  digitalWrite (in1x,LOW);
   digitalWrite (in2x,HIGH);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,HIGH);

}

void Stop ()
{
////////////////////////////////////////////
//stopping the motor drivers
  digitalWrite (in1,LOW);
  digitalWrite (in2,LOW);
  digitalWrite (in3,LOW);
  digitalWrite (in4,LOW);
  //stopping the motor driver B
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,LOW);
}


void demoOne ()
{
  //this function will run the motor in both directions
  /////////////////////////////////////////
////////////////////////////////////////////
//stopping the motor drivers
  digitalWrite (in1,LOW);
  digitalWrite (in2,LOW);
  digitalWrite (in3,LOW);
  digitalWrite (in4,LOW);
  //stopping the motor driver B
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,LOW);
}

void strictLeft()
{
  digitalWrite (in1,LOW);
  digitalWrite (in2,HIGH);
  digitalWrite (in3, HIGH);
  digitalWrite (in4,LOW);
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,HIGH);
  digitalWrite (in3x,HIGH);
  digitalWrite (in4x,LOW);
}

void strictRight()
{
 digitalWrite (in1,HIGH);
  digitalWrite (in2,LOW);
  digitalWrite (in3,LOW);
  digitalWrite (in4,HIGH); 
  digitalWrite (in1x,HIGH);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,HIGH);
}

void frontRight() {
  digitalWrite (in1,HIGH);
  digitalWrite (in2,LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4,LOW);
  digitalWrite (in1x,HIGH);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,LOW);
}

void frontLeft()  {
  digitalWrite (in1,LOW);
  digitalWrite (in2,LOW);
  digitalWrite (in3, HIGH);
  digitalWrite (in4,LOW);
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,HIGH);
  digitalWrite (in4x,LOW);
}

void rearRight()  {
  digitalWrite (in1,LOW);
  digitalWrite (in2,HIGH);
  digitalWrite (in3, LOW);
  digitalWrite (in4,LOW);
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,HIGH);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,LOW);
}

void rearLeft() {
  digitalWrite (in1,LOW);
  digitalWrite (in2,LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4,HIGH);
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,LOW);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,HIGH);
}

void demoTwo()
 {
  digitalWrite (in1,LOW);
  digitalWrite (in2,HIGH);
  digitalWrite (in3,LOW);
  digitalWrite (in4,HIGH);
  //accelerates from 0 to 1055 max speed of motor driver A
  for(int i=0;i<1055;i++)
  {
    analogWrite (enA,i);
    analogWrite (enB,i);
  
  {
  digitalWrite (in1x,LOW);
  digitalWrite (in2x,HIGH);
  digitalWrite (in3x,LOW);
  digitalWrite (in4x,HIGH);
  //accelerating from 0~1055 max speed of driver B
  for(int i=0;i<=1055;i++)
    {
    analogWrite (enAx,i);
    analogWrite (enBx,i);
  }
  }
}

   //decelerates from max to zero
    for(int i=0;i>=1055;--i)
    {
      digitalWrite (in1,LOW);
      digitalWrite (in2,LOW);
      digitalWrite (in3,LOW);
      digitalWrite (in4,LOW);
    {
        for(i=0;i>=1055;--i)
        {
          digitalWrite (in1x,LOW);
          digitalWrite (in2x,LOW);
          digitalWrite (in3x,LOW);
          digitalWrite (in4x,LOW);
        }
      }
    }
 }



void loop() {
  velocity = map(ch3, 1000,2000,0,1055);
   //setting the motor speed from 0~1055 max speed
  analogWrite (enA,velocity);
  analogWrite (enAx,velocity);
  analogWrite (enB,velocity);
analogWrite (enBx,velocity);
     
     if(ch2>1600)
    {
      if(ch1>1600)
        frontRight();
      else if(ch1<1400)
        frontLeft();
      else
        forward();
    }
    else if(ch2<1400)
    {
      if(ch1>1600)
        rearRight();
      else if(ch1<1400)
        rearLeft();
      else
        backward();
    }
    else if(ch1>1600)
    {
      strictRight();
    }
    else if(ch1<1400)
    {
      strictLeft();
    }
    else,
    {
     Stop();
    } 
    
    
   //put your main code here, to run repeatedly:
  Serial.print(ch1);
  Serial.print(" . ");
  Serial.print(ch2);
  Serial.print(" . ");
  Serial.println(ch3);
    }
