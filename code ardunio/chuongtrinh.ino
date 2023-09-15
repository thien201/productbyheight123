#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal LCD(12,11,5,4,3,2);
Servo servo;
int sensorPin1=6;
int sensorPin2=8;
int resetPin=9;
int cao=0,thap=0,tong=0;
int sensor1,sensor2,reset;

void setup() {
    LCD.begin(16,2);
    LCD.print("SP:cao thap tong");
    LCD.setCursor(0,1);
    LCD.print("SL:");
    pinMode(sensorPin1,INPUT);
    pinMode(sensorPin2,INPUT);
    pinMode(resetPin,INPUT);
    servo.attach(7); 
    servo.write(0);
    }
    
void loop() {

  reset=digitalRead(9);
  sensor1=digitalRead(6);
  sensor2=digitalRead(8);
  
  if(sensor1==0){
    cao=cao+1;
    delay(100);
    servo.write(50);
    delay(4000);
    servo.write(0);
    }

  if(sensor2==0){
    thap=thap+1;
    delay(1000);
    }
    
  if(reset==0){
    cao=0;
    thap=0;
    tong=0;
    LCD.setCursor(5,1);
    LCD.print(" ");
    LCD.setCursor(9,1);
    LCD.print(" ");
    LCD.setCursor(14,1);
    LCD.print(" ");
    }

  tong = cao + thap;
 
  LCD.setCursor(4,1);
  LCD.print(cao);
  LCD.setCursor(8,1);
  LCD.print(thap);
  LCD.setCursor(13,1);
  LCD.print(tong);
}
