#include <Servo.h>
Servo myservo;

#define G_led 2 
#define R_led 3

#define echopin 4 
#define trigpin 5 

int cm;
int degree=0, flag=0;
int set_time=2000;
long rememTime;

void setup(){ 
Serial.begin(9600);

myservo.attach(8);
myservo.write(degree);  

pinMode(R_led,OUTPUT); 
pinMode(G_led,OUTPUT); 
pinMode(trigpin, OUTPUT); 
pinMode(echopin, INPUT);  
delay(500);
}
 
void loop(){  
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);

long ultra_time = pulseIn (echopin, HIGH);
cm =  ultra_time / 29 / 2;

Serial.print("cm:");Serial.println(cm);

if(cm<10)rememTime = millis(); 

if((millis()- rememTime) > set_time){
digitalWrite(G_led, LOW);   
digitalWrite(R_led, HIGH); 
if(flag==1){ flag=0;
for(degree=90; degree>0; degree-=1){
myservo.write(degree);  
delay(3);
  }    
 }
}else{
digitalWrite(G_led, HIGH); 
digitalWrite(R_led, LOW);
if(flag==0){ flag=1;
for(degree=0; degree<90; degree+=1){
myservo.write(degree);  
delay(3);    
  }    
 }
}

delay(100);
