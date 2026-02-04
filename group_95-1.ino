/*
  ELEC1100 Your Lab#06 & Project Template

  To program the car tracking the white line on a dark mat

  Group No. (number of your project box):  
  Group Member 1 (name & SID): Chow Yuet Hey 21008043
  Group Member 2 (name & SID): Wong Sze Ting 21054602
  
*/

// assign meaningful names to those pins that will be used

const int pinL_Sensor = A5;      //pin A5: left sensor 
const int pinB_Sensor = A4;      //pin A4: bumper sensor
const int pinR_Sensor = A3;      //pin A3: right sensor 

const int pinL_PWM = 9;          //pin D9: left motor speed
const int pinL_DIR = 10;         //pin D10: left motor direction

const int pinR_PWM = 11;         //pin D11: right motor speed
const int pinR_DIR = 12;         //pin D12: right motor direction

//define variables to be used in script

int bumperSensor = 1;  // not sensing white
int leftSensor = 1;    // not sensing white
int rightSensor = 1;   // not sensing white

int countBumper = 0;   // bumper sensor not triggered yet

int count00 = 1;

void go_straight ()
{
    
  if ( !leftSensor && rightSensor ) {
    analogWrite(pinL_PWM, 200);
    analogWrite(pinR_PWM, 250);
    digitalWrite(pinL_DIR, 0);
    digitalWrite(pinR_DIR, 1); 
   
  }
    
  if ( leftSensor && !rightSensor ) {
    analogWrite(pinL_PWM, 250);
    analogWrite(pinR_PWM, 200);
    digitalWrite(pinL_DIR, 1);
    digitalWrite(pinR_DIR, 0); 
    
  }
  
  if ( leftSensor && rightSensor ) {
    analogWrite(pinL_PWM, 170);
    analogWrite(pinR_PWM, 170);
    digitalWrite(pinL_DIR, 1);
    digitalWrite(pinR_DIR, 1);
  }

}

void setup ()
{
  // define pins as input and output
  pinMode(pinB_Sensor, INPUT);
  pinMode(pinL_Sensor, INPUT);
  pinMode(pinR_Sensor, INPUT);
  
  pinMode(pinL_DIR, OUTPUT);
  pinMode(pinR_DIR, OUTPUT);
  
  pinMode(pinL_PWM, OUTPUT);
  pinMode(pinR_PWM, OUTPUT);
  
  // initialize output pins
  digitalWrite(pinL_DIR, HIGH);   //forward direction    
  digitalWrite(pinR_DIR, HIGH);   //forward direction
  analogWrite(pinL_PWM, 0);       //stop at the start position 
  analogWrite(pinR_PWM, 0);       //stop at the start position 
}

// the loop function runs over and over again forever

void loop() {

  // Arduino is reading the sensor measurements
  bumperSensor = digitalRead(pinB_Sensor);
  leftSensor = digitalRead(pinL_Sensor);
  rightSensor = digitalRead(pinR_Sensor);
  
  // car stops at the start position when bumper sensor no trigger
  if ( bumperSensor && countBumper == 0 ) {
    analogWrite(pinL_PWM, 0);
    analogWrite(pinR_PWM, 0);
  }

  // bumper sensor is triggered at the start position for the 1st time
  else if ( !bumperSensor && countBumper == 0) {
    analogWrite(pinL_PWM, 200);
    analogWrite(pinR_PWM, 200);
    countBumper = countBumper + 1;
    delay(350);     //to let the car leave the start position with no miscount
  }
  
  // car is tracking on the white line
  else if ( bumperSensor == 1 && countBumper == 1) 
  { 

    go_straight();

    
    if ( !leftSensor && !rightSensor ) {// turn left
      
        analogWrite(pinL_PWM, 245);
        analogWrite(pinR_PWM, 245);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1); 
        if(count00 == 1){
          count00 = count00 + 1;
        }
        delay(200);
    }
  }

  else if ( count00 == 2){
    go_straight();
     if ( !leftSensor && !rightSensor ){ // turn left
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
      count00 = count00 + 1;
      delay(200);
    }
  }

  else if ( count00 == 3){
      if ( !leftSensor && !rightSensor ){ // left white right white
      analogWrite(pinL_PWM, 100);
      analogWrite(pinR_PWM, 100);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1); 
      delay(50);
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
      
      count00 = count00 + 1;
      delay(200);
    }

    go_straight();

  }
    else if ( count00 == 4 ){
    // turn left go outside the loop
    if ( !leftSensor && !rightSensor ){
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
      if(count00 == 4)
        count00 = count00 + 1;
      delay(200);
    }

    go_straight();

    }

    else if ( count00 == 5){
      if ( !leftSensor && !rightSensor ){
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
      
      count00 = count00 + 1;
      delay(200);
    }

    go_straight();
  }

  else if ( count00 == 6){
    if ( !leftSensor && !rightSensor ){
      analogWrite(pinL_PWM, 100);
      analogWrite(pinR_PWM, 100);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1); 
      delay(50);
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 0); 
      
      count00 = count00 + 1;
      delay(200);
    }

    go_straight();

  }

  else if ( count00 == 7){
    
    if ( !leftSensor ){
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
    
      count00 = count00 + 1;
      delay(200);
    }

    go_straight();

  }

  else if ( count00 == 8){
    if ( !leftSensor ){
      analogWrite(pinL_PWM, 100);
      analogWrite(pinR_PWM, 100);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1); 
      delay(150);
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
      if(count00 == 8)
        count00 = count00 + 1;
      delay(200);
    }

    go_straight();
  }

  else if (count00 == 9){
    if (!leftSensor && !rightSensor) {
      analogWrite(pinL_PWM, 100);
      analogWrite(pinR_PWM, 100);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1); 
      delay(50);
      analogWrite(pinL_PWM, 245);
      analogWrite(pinR_PWM, 245);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1); 
      if(countBumper == 9){
        count00 = count00 + 1;
      delay(200);
     }
     go_straight();

    }
  else if ( count00 == 10 ){
    if ( !leftSensor && !rightSensor ){
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 0); 
      delay(1500);   
      
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1); 
      if(count00 == 10)
        count00 = count00 + 1;
      delay(75);
    }
    
    go_straight();
  }
  else if ( countBumper == 11 ){
    // 90 turn
    if( bumperSensor ){
      if ( !leftSensor && rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 250);
          digitalWrite(pinL_DIR, 0);
          digitalWrite(pinR_DIR, 1); 
       }
        
      if ( leftSensor && !rightSensor ) {
        analogWrite(pinL_PWM, 250);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0); 
      }
      if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 180);
        analogWrite(pinR_PWM, 180);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);
      }  
    }
    // get a white wall then go back
    if ( !bumperSensor ){
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 0); 
      countBumper = 12;
      delay(400);   
    }
  }

else if( count00 == 12 ){
    // stop the car
    analogWrite(pinL_PWM, 0);
    analogWrite(pinR_PWM, 0);
  }
}
}
