
float temp0;
int tempPin0 = A0;
int i,count=0,count1=0;
void setup()
{

Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);

}

void loop()

{
digitalWrite(6,1);
temp0 = analogRead(tempPin0);
temp0 = temp0 * 0.48828125;
Serial.print(temp0);
Serial.println("*C");

if((temp0>28) && (temp0<40))
{
  digitalWrite(5,1);
  digitalWrite(4,0);
}
else if(temp0>=40)
{
digitalWrite(4,1);
digitalWrite(5,0);
}
else
{
digitalWrite(4,0);
digitalWrite(5,0);
}
delay(1000);
}

