# include<ESP32Servo.h>
# include<NewPing.h>
Servo Servo1;
#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   27          // Enable/speed motors Left         GPIO27(D27)
#define IN_1  2          // L298N in1 motors Right           GPIO2(D2)
#define IN_2  15          // L298N in2 motors Right           GPIO15(D15)
#define IN_3  4           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  0           // L298N in4 motors Left            GPIO0(D3)
//#define Button 25        // For switch connected to GPIO25
const int trig=13;              // Triger part of ultrasonic sensor connected  GPIO13(D13)
 const int echo=12;             // echo part of ultrasonic sensor connected  GPIO12(D12)
 NewPing sonar(trig,echo,500);   // its deffault range is 500 itself
int Led_builtin=2;

int distance =100;
   int readping(){
  delay(70);
  int centi_meter=sonar.ping_cm();
  if (centi_meter==0){
    centi_meter=250;
  }
  return centi_meter;
}
  int lookRight(){
    Servo1.write(50); 
    delay(500);
    int distance = readping();
    delay(100);
    Servo1.write(115); 
    return distance;
}

int lookLeft()
{
    Servo1.write(170); 
    delay(500);
    int distance = readping();
    delay(100);
    Servo1.write(115); 
    return distance;
    delay(100);
}


void setup(){
  Servo1.attach(26);    //PWM is connected to GPIO26
  Serial.begin(115200);
  

  pinMode(trig,OUTPUT);         // For ultrasonic sencor
  pinMode(echo,INPUT);
  Serial.begin(9600);
  pinMode(Led_builtin, OUTPUT);
//  pinMode(Button,INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);  
  pinMode(IN_1, OUTPUT);     // For motor
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT); 
    delay(2000);
  distance = readping();
  delay(100);
  distance = readping();
  delay(100);
  distance = readping();
  delay(100);
  distance = readping();
  delay(100);

}

 void goAhead(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, 800);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, 800);
  }

void goBack(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 800);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 800);
  }

void goRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 800/3);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, 800/3);
  }

void goLeft(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, 800/3);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 800/3);
  }
void stop(){  
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 0);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 0);
 }
void loop(){


 int distanceR = 0;
 int distanceL =  0;
 delay(40);
  if(distance<=15)
 {
  stop();
  delay(100);
  goBack();
  delay(300);
  stop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    goRight();
    stop();
  }else
  {
    goLeft();
    stop();
  }
 }else
 {
  goAhead();
 }
 distance = readping();

}
