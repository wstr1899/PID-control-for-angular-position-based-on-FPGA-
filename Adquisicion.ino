#define ENABLE 5
#define DIRA 3
#define DIRB 4
int pot=1;
int val=0;
int i;
int f1=0;
int f2=0;
int f3=0;
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
unsigned long t; 
void setup() {
  //---set pin direction
  startMillis = millis();  //initial start time
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
    Serial.begin(250000);
}
void hor(){
  analogWrite(ENABLE,255);
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,HIGH);
}
void ant(){
  analogWrite(ENABLE,255);
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,LOW);
}
void paro(){
  analogWrite(ENABLE,0);
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,LOW);
}
void loop() {
  currentMillis = millis();
  t=currentMillis-startMillis;
  val=analogRead(pot);
  Serial.print(val);
  Serial.print(",");
  Serial.print(t);
  Serial.print("\n");
  if (val<440){
    f1=1;
    f2=0;
  }
  if (val>600){
    f2=1;
    f1=0;
  }
 
  if (f1==1){
    hor();}
  if (f2==1){
    ant();
  }
  
    
  
}
   
