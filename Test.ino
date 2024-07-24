#define MA1 4
#define MA2 5
#define MB1 6
#define MB2 7
#define MAS A1
#define MBS A0
#define S1 12
#define S2 11
#define S3 10
#define S4 9
#define S5 8
int speed = 150;
void stop();
void forward(int);
void backward(int);
void left(int, int);
void right(int, int);
void setup() {
  // put your setup code here, to run once:
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(MAS, OUTPUT);
  pinMode(MBS, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  stop();
}

void loop() {
 // put your main code here, to run repeatedly:
  if(digitalRead(S1) == 0 && digitalRead(S2) == 0 && digitalRead(S3) == 1 && digitalRead(S4) == 0 && digitalRead(S5) == 0)
  {
    forward(220);
  }
  if(digitalRead(S1) == 0 && digitalRead(S2) == 1 && digitalRead(S3) == 0 && digitalRead(S4) == 0 && digitalRead(S5) == 0)
  {
    left(220, 1);
  }
  if(digitalRead(S1) == 1 && digitalRead(S2) == 0 && digitalRead(S3) == 0 && digitalRead(S4) == 0 && digitalRead(S5) == 0)
  {
    left(220, 0);
  }
  if(digitalRead(S1) == 0 && digitalRead(S2) == 0 && digitalRead(S3) == 0 && digitalRead(S4) == 1 && digitalRead(S5) == 0)
  {
    right(220, 1);
  }
  if(digitalRead(S1) == 0 && digitalRead(S2) == 0 && digitalRead(S3) == 0 && digitalRead(S4) == 0 && digitalRead(S5) == 1)
  {
    right(220, 0);
  }
  if(digitalRead(S1) == 1 && digitalRead(S2) == 1 && digitalRead(S3) == 1 && digitalRead(S4) == 1 && digitalRead(S5) == 1)
  {
    stop();
  }
}
void forward(int speed)
{
  analogWrite(MAS, speed);
  analogWrite(MBS, speed);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}
void backward(int speed)
{
  analogWrite(MAS, speed);
  analogWrite(MBS, speed);
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
}
void left(int speed, int mode)
{
  if(mode == 0)
  {
    analogWrite(MAS, speed);
    analogWrite(MBS, speed);
    digitalWrite(MA1, HIGH);
    digitalWrite(MA2, LOW);
    digitalWrite(MB1, HIGH);
    digitalWrite(MB2, LOW);
  }
  if(mode == 1)
  {
    analogWrite(MAS, speed);
    analogWrite(MBS, speed);
    digitalWrite(MA1, LOW);
    digitalWrite(MA2, LOW);
    digitalWrite(MB1, HIGH);
    digitalWrite(MB2, LOW);
  }  
}
void right(int speed, int mode)
{
  if(mode == 0)
  {
    analogWrite(MAS, speed);
    analogWrite(MBS, speed);
    digitalWrite(MA1, LOW);
    digitalWrite(MA2, HIGH);
    digitalWrite(MB1, LOW);
    digitalWrite(MB2, HIGH);
  }
  if(mode == 1)
  {
    analogWrite(MAS, speed);
    analogWrite(MBS, speed);
    digitalWrite(MA1, LOW);
    digitalWrite(MA2, HIGH);
    digitalWrite(MB1, LOW);
    digitalWrite(MB2, LOW);
  }  
}
void stop()
{
  analogWrite(MAS, 0);
  analogWrite(MBS, 0);
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
}