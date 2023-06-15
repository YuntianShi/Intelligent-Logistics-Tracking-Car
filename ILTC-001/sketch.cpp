#include <Arduino.h>

const int sw1 = 8;
const int sw2 = 9;
const int sw3 = 10;
const int sw4 = 11;
//���⴫�����˿�
const int LMF = 5;
const int LMB = 4;
const int RMF = 3;
const int RMB = 2;
//L298N������˿�
const int s1 = 6;
const int s2 = 7;
const int s3 = 12;
//�̵�����Ͷ���ã�
const int s = 13;
//������
int m0 = 0;
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;
//Ͷ���ñ���
int Lv = 110;
int Rv = 110;
//�ٶ�

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
//�ӳ�1s����

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
//�Զ�����

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
  m1 = 1;

digitalWrite(LMF,HIGH);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,HIGH);
digitalWrite(s1,HIGH);
delay(800);
digitalWrite(s1,LOW);
while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
}
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
  m2 = 1;

digitalWrite(LMF,HIGH);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,HIGH);
digitalWrite(s1,HIGH);
delay(100);
digitalWrite(s2,HIGH);
delay(800);
digitalWrite(s1,LOW);
digitalWrite(s2,LOW);
while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
}
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
  m3 = 1;

digitalWrite(LMF,HIGH);
digitalWrite(LMB,HIGH);
digitalWrite(RMF,HIGH);
digitalWrite(RMB,HIGH);
digitalWrite(s1,HIGH);
delay(100);
digitalWrite(s2,HIGH);
delay(100);
digitalWrite(s3,HIGH);
delay(800);
digitalWrite(s1,LOW);
digitalWrite(s2,LOW);
digitalWrite(s3,LOW);
while(digitalRead(sw2)==0 or digitalRead(sw4)==0)
{

analogWrite(LMF,Lv);
digitalWrite(LMB,LOW);
analogWrite(RMF,Rv);
digitalWrite(RMB,LOW);
}
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
