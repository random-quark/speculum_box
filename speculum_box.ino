#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servo1Pin = 6;
const int servo2Pin = 9;
const int servo3Pin = 10;
const int servo4Pin = 11;

int threshold = 750;
bool sendingState = false;


int previousLDRValue, currentLDRValue;


void setup() {

  Serial.begin(9600);

  
  previousLDRValue = 0;
  currentLDRValue = 0;
  
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);

  //Start Positions
  servo1.write(80);
  servo2.write(73);
  servo3.write(95);
  servo4.write(128);

  previousLDRValue = analogRead(A0);
  currentLDRValue = analogRead(A0);
}

void loop() {

  currentLDRValue = analogRead(A0);

  Serial.print("actual value: ");
  Serial.println(currentLDRValue);

    // check the delta
  int delta = previousLDRValue - currentLDRValue;
  if (delta > 50 && !sendingState){
    sendingState = true;

    Serial.println("Running");
    doRun();
    
  }
  
  
  previousLDRValue = currentLDRValue;
}

void doRun(){
  
    delay(3200);
  
    servo1.write(102);
    delay(600);
    servo1.write(80);//Reset
    delay(100);
  
    servo2.write(95);
    delay(900);
    servo2.write(73);//Reset
    delay(2700);
  
    servo3.write(83);
    delay(1900);
    servo3.write(95);//Reset
    delay(4100);
  
    servo4.write(115);
    delay(300);
    servo4.write(128);//Reset
    delay(1000);

    sendingState = false;
    
}


