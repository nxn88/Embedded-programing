#include <Arduino.h>
<<<<<<< HEAD
 int led[]={6,7,8,9,10,11,12,13};
int digit[]={5,4,3,2};
int i=0;
int delayTime=50;
long lastTime=0;
int tem1,tem2,tem3,tem4;

void out8bit(unsigned char data);
void calculate(int val);
void display();

void setup() 
{                
  for(int i=0; i<=7; i++)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i],LOW);
  } 
  pinMode(digit[0], OUTPUT);
  pinMode(digit[1], OUTPUT);
  pinMode(digit[2], OUTPUT);
  pinMode(digit[3], OUTPUT);
=======

int led1 = 13;
int led2 = 12;
int sw1 = 2;
bool sw_state=0,last_sw_state,buttonstate=1,change=0;
bool state=0;
unsigned long time1;
int debounceDelay=40;
bool LED1State=0;
unsigned long delayTime1;
unsigned long delayA0;
//prototype
void checkSW();
void setup() 
{
  pinMode(led1,OUTPUT);  
  pinMode(led2,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(sw1,INPUT_PULLUP);  
>>>>>>> 3255543586ad25bd55b840e2401187086f739e74
  Serial.begin(115200);
}

void loop() 
{
  if(millis()-lastTime>delayTime)
  {
    i = analogRead(A0);
    //if(i<1999) i++;
    // else i=0;
      Serial.print("i=");
    Serial.println(i);
    lastTime=millis();
    calculate(i);
  }
  display();
}

void calculate(int val)
{
  tem4=(val/1000);
  tem3=((val%1000)/100);
  tem2=(((val%1000)%100)/10);
  tem1=(((val%1000)%100)%10);

  if(tem4==0) tem4=10;
  if((tem3==0)&&(tem4==10)) tem3=10;
  if((tem2==0)&&(tem4==10)&&(tem3==10)) tem2=10;
}

void display()
{
  for(int sel=0;sel<4;sel++)
  {
    digitalWrite(digit[0],HIGH);
    digitalWrite(digit[1],HIGH);
    digitalWrite(digit[2],HIGH);
    digitalWrite(digit[3],HIGH);
    if(sel==0) {out8bit(tem1); digitalWrite(digit[0],LOW);}
    else if(sel==1) {out8bit(tem2); digitalWrite(digit[1],LOW);}
    else if(sel==2) {out8bit(tem3); digitalWrite(digit[2],LOW);}
    else if(sel==3) {out8bit(tem4); digitalWrite(digit[3],LOW);}
    delay(2);
  }
}

const char segment[]={  B00111111,
                        B00000110,
                        B01011011,
                        B01001111,
                        B01100110,
                        B01101101,
                        B01111101,
                        B00000111,
                        B01111111,
                        B01101111,
                        B00000000 };

void out8bit(unsigned char data)
{
  digitalWrite(led[0],segment[data] & B00000001);
  digitalWrite(led[1],segment[data] & B00000010);
  digitalWrite(led[2],segment[data] & B00000100);
  digitalWrite(led[3],segment[data] & B00001000);
  digitalWrite(led[4],segment[data] & B00010000);
  digitalWrite(led[5],segment[data] & B00100000);
  digitalWrite(led[6],segment[data] & B01000000);
  digitalWrite(led[7],segment[data] & B10000000);
}
