int m1 = 10;
int m2 = 11;
int m3 = 5;
int m4 = 6;

int Il = 1;
int Ir = 2;
int Ib = 3;

bool I_l;
bool I_r;
bool I_b;

int trigPin = 7;
int echoPin = 4;
long duration;
int distance;


void setup() 
{
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IRB,INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;
  
  I_l = digitalRead(Il);
  I_r = digitalRead(Ir);
  I_b = digitalRead(Ib);
  
  if(distance >= 10 && distance <= 30)
  {
    if(I_l == 1 & I_r == 1)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }
    else if(I_l == 0 & I_r == 1)
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }
    else if(I_l == 1 & I_r == 0)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);
    }
    else
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
    }
  }
  else if(distance <= 5 && I_b == 1)
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  }
  else
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
  }
}
