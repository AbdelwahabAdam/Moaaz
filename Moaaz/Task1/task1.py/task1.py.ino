#include <Servo.h>

int In1=13;
int Out1=12;
int In2=11;
int Out2=10;
int ServoPin=9;

void setup() {
  pinMode(In1, INPUT);
  pinMode(In2, INPUT);
  pinMode(Out1, OUTPUT);
  pinMode(Out2, OUTPUT);
  myservo.attach(ServoPin);


}

void loop() {
  if (In1 == "HIGH") {
    digitalWrite(Out1,HIGH);
    //myservo.write(pos); 
    }

   if (In2 == "HIGH") {
    digitalWrite(Out2,HIGH);
    //myservo.write(pos); 
    }
}
