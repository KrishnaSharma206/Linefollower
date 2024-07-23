#define MAS A1
#define MBS A0
#define S1 12
#define S2 11
#define S3 10
#define S4 9
#define S5 8
char stop();
char forward();
char backward();
char left(int);
char right(int);
void setup() {
  // put your setup code here, to run once:
  pinMode(MAS, OUTPUT);
  pinMode(MBS, OUTPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  analogWrite(MAS, 0);
  analogWrite(MBS, 0);
  Serial.begin(9600);
}

void loop() {
 // put your main code here, to run repeatedly:
  if(digitalRead(S1) == 0 && digitalRead(S2) == 0 && digitalRead(S3) == 1 && digitalRead(S4) == 0 && digitalRead(S5) == 0)
  {
    Serial.println(forward());
  }
  if(digitalRead(S1) == 0 && digitalRead(S2) == 1 && digitalRead(S3) == 0 && digitalRead(S4) == 0 && digitalRead(S5) == 0)
  {
    Serial.println(left(1));
  }
  if(digitalRead(S1) == 1 && digitalRead(S2) == 0 && digitalRead(S3) == 0 && digitalRead(S4) == 0 && digitalRead(S5) == 0)
  {
    Serial.println(left(0));
  }
  if(digitalRead(S1) == 0 && digitalRead(S2) == 0 && digitalRead(S3) == 0 && digitalRead(S4) == 1 && digitalRead(S5) == 0)
  {
    Serial.println(right(1));
  }
  if(digitalRead(S1) == 0 && digitalRead(S2) == 0 && digitalRead(S3) == 0 && digitalRead(S4) == 0 && digitalRead(S5) == 1)
  {
    Serial.println(right(0));
  }
  if(digitalRead(S1) == 1 && digitalRead(S2) == 1 && digitalRead(S3) == 1 && digitalRead(S4) == 1 && digitalRead(S5) == 1)
  {
    Serial.println(stop());
  }
}
char forward()
{
  return('F');
}
char backward()
{
  return('B');
}
char left(int mode)
{
  if(mode == 0)
  {
    return('L');
  }
  if(mode == 1)
  {
    return('l');
  }  
}
char right(int mode)
{
  if(mode == 0)
  {
    return('R');
  }
  if(mode == 1)
  {
    return('r');
  }  
}
char stop()
{
  return('S');
}