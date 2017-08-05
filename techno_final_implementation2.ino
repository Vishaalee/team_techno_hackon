#include <Time.h>
#include <TimeLib.h>
int r,s,count=0;
time_t t;
float temp0;
int tempPin0 = A0;

void setup()
{

Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop()

{
  digitalWrite(6,1);
  temp0=analogRead(tempPin0);
  temp0=temp0*0.48828125;
time_t t=now();
s=second(t);
r=minute(t);
Serial.println(r);
Serial.println(s);
Serial.println(temp0);

if(temp0>28 && temp0<40)
{
count=0;
digitalWrite(5,1);
digitalWrite(4,0);
Serial.println("Phase2 is on");
if(r>=1 && r<2)
  {
  digitalWrite(4,1);
  Serial.println("Burglar Alarm on");
}
else
{
  digitalWrite(4,0);
}}
else if(temp0>32)
{
  digitalWrite(5,0);
digitalWrite(4,1);
Serial.println("Fire alarm");
}
else
{
count++;
if(count>2)
{
  digitalWrite(5,0);
  digitalWrite(4,0);
  Serial.println("time limit");
}
}
delay(1000);
}

