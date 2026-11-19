#include <Arduino.h>

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
  Serial.begin(115200);
}

void loop() 
{
  // checkSW();
  // if(state==0){ digitalWrite(led2,LOW);} 
  // else{ digitalWrite(led2,HIGH);}
  
   if ((millis() - delayTime1) > 500)
   {
    LED1State=!LED1State;
   digitalWrite(13, LED1State);
    delayTime1=millis();
   }

  if ((millis() - delayA0) > 500)
  {
  
   int sensorValue = analogRead(A0);
   int PWM = map(sensorValue,0,1023,0,255);
   analogWrite(6,PWM);

   if (sensorValue >=800){
    digitalWrite(led2,1);
   }
   else if (sensorValue <=400){
    digitalWrite(6,1);

   }
   else if (sensorValue <=800 && sensorValue >=400){
    digitalWrite(10,1);
   }
   
   
   Serial.print("sensorValue: " );
   Serial.print(sensorValue);
   Serial.print( "  PWM: ");
   Serial.print(PWM);
   float volt = sensorValue*5.0/1024;
   Serial.print("  volt:");
   Serial.println(volt);
   delayA0=millis();
  }



}                                                                     


void checkSW()
{
  sw_state=digitalRead(sw1);
  if(sw_state!= last_sw_state)
  {
    time1=millis();
  }
  if((millis()-time1)>debounceDelay)
  {
    if(buttonstate!=sw_state)
    {
    buttonstate=sw_state;
    change=1;
    }   
  }

  if((buttonstate==0)&&(change==1))
  {
    state=!state; 
    change=0;
  }
  if((buttonstate==1)&&(change==1))
  {
    change=0;
  }
  last_sw_state=sw_state;
}


//https://github.com/knandas/digi/blob/main/arduino1.c