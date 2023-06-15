#include <Arduino.h>

const int sw1 = 8;
const int sw2 = 9;
const int sw3 = 10;
const int sw4 = 11;
//红外传感器端口
const int LMF = 5;
const int LMB = 4;
const int RMF = 3;
const int RMB = 2;
//L298N驱动板端口
const int s1 = 6;
const int s2 = 7;
const int s3 = 12;
//继电器（投放用）
const int s = 13;
//启动键
int m0 = 0;
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;
//投放用变量
int Lv = 180;
int Rv = 180;
//速度
int t1 = 0;
int t2 = 0;
int t3 = 0;

void setup() {
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(LMF,OUTPUT);
pinMode(LMB,OUTPUT);
pinMode(RMF,OUTPUT);
pinMode(RMB,OUTPUT);
pinMode(s1,OUTPUT);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(s,INPUT);


delay(2000);
//延迟1s启动

while(m0 == 0)
{
if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
while(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
while(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
}

while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);

}
if(digitalRead(sw2)==0 and digitalRead(sw4)==0)
{
  m0 = 1;

digitalWrite(LMF,HIGH);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,HIGH);

while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
}
}
}
//自动对齐

while(m1 == 0)
{
if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
}

while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);

}
if(digitalRead(sw2)==0 and digitalRead(sw4)==0)
{
  m1 = 1;

while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t1 = t1 + 1;
//delay(1);
}

while(t1 < 4000)
{
  if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t1 = t1 + 1;
//delay(1);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t1 = t1 + 1;
//delay(1);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t1 = t1 + 1;
//delay(1);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t1 = t1 + 1;
//delay(1);
}
}
if(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t1 = t1 + 1;

}
}

digitalWrite(s1,HIGH);

while(t1 < 7000)
{
  if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t1 = t1 + 1;
//delay(1);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t1 = t1 + 1;
//delay(1);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t1 = t1 + 1;
//delay(1);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t1 = t1 + 1;
//delay(1);
}
}
if(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t1 = t1 + 1;

}
}
digitalWrite(s1,LOW);
}
}
//---------------------------------------------------1--------------------------------------------------
while(m2 == 0)
{
if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
}

while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);

}
if(digitalRead(sw2)==0 and digitalRead(sw4)==0)
{
  m2 = 1;

while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t2 = t2 + 1;
//delay(1);
}

while(t2 < 4000)
{
  if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t2 = t2 + 1;
//delay(1);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t2 = t2 + 1;
//delay(1);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t2 = t2 + 1;
//delay(1);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t2 = t2 + 1;
//delay(1);
}
}
if(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t2 = t2 + 1;

}
}

digitalWrite(s1,HIGH);
digitalWrite(s2,HIGH);

while(t2 < 7000)
{
  if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t2 = t2 + 1;
//delay(1);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t2 = t2 + 1;
//delay(1);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t2 = t2 + 1;
//delay(1);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t2 = t2 + 1;
//delay(1);
}
}
if(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t2 = t2 + 1;

}
}
digitalWrite(s1,LOW);
digitalWrite(s2,LOW);
}
}
//---------------------------------------------------2--------------------------------------------------
while(m3 == 0)
{
if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
}

while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);

}
if(digitalRead(sw2)==0 and digitalRead(sw4)==0)
{
  m3 = 1;

while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t3 = t3 + 1;
//delay(1);
}

while(t3 < 4000)
{
  if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t3 = t3 + 1;
//delay(1);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t3 = t3 + 1;
//delay(1);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t3 = t3 + 1;
//delay(1);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t3 = t3 + 1;
//delay(1);
}
}
if(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t3 = t3 + 1;

}
}

digitalWrite(s1,HIGH);
digitalWrite(s2,HIGH);
digitalWrite(s3,HIGH);
while(t3 < 8000)
{
  if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t3 = t3 + 1;
//delay(1);
}
while(digitalRead(sw3)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
t3 = t3 + 1;
//delay(1);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t3 = t3 + 1;
//delay(1);
}
while(digitalRead(sw2)==0 and digitalRead(sw1)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
t3 = t3 + 1;
//delay(1);
}
}
if(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
t3 = t3 + 1;

}
}
digitalWrite(s1,LOW);
digitalWrite(s2,LOW);
digitalWrite(s3,LOW);

}
}
//---------------------------------------------------3--------------------------------------------------
while(m4 == 0)
{
if(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,LOW);
}
while(digitalRead(sw2)==1 and digitalRead(sw4)==0)
{
digitalWrite(LMF,LOW);
digitalWrite(LMB,HIGH);
analogWrite(RMF,255);
digitalWrite(RMB,LOW);
}
}

if(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
digitalWrite(LMF,HIGH);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
while(digitalRead(sw2)==0 and digitalRead(sw4)==1)
{
analogWrite(LMF,255);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,HIGH);
}
}

while(digitalRead(sw2)==1 and digitalRead(sw4)==1)
{
analogWrite(LMF,150);
digitalWrite(LMB,LOW);
analogWrite(RMF,150);
digitalWrite(RMB,LOW);

}
if(digitalRead(sw2)==0 and digitalRead(sw4)==0)
{
  m4 = 1;

digitalWrite(LMF,LOW);
digitalWrite(LMB,LOW);
digitalWrite(RMF,LOW);
digitalWrite(RMB,LOW);


}
}

}
void loop() {


}

