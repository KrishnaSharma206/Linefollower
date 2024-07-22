#define MA1 4
#define MA2 5
#define MB1 6
#define MB2 7
#define MAS A1
#define MBS A0
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
  analogWrite(MAS, 0);
  analogWrite(MBS, 0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward(speed);
  delay(1000);
  backward(speed);
  delay(1000);
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