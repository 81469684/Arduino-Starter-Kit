/*part7  USE encode CONTROL Servos
Turn the rotary encoder control servos
  */
#include <Servo.h>//load servo library
int clk= 2;// The digital 2 pin,read clk
int data= 4;// The digital 4 pin,read data
int servos = 8;// The 6 pin,driving the servos
Servo servo;//Get a servo controller
int angle=90;//set the servo default angle
void setup() {
  pinMode(data,INPUT);// initialize the data pin as an input.
  pinMode(clk,INPUT);// initialize the clk pin as an input.
  servo.attach(servos);  //attach servos pin to servo controller
 // attachInterrupt(0,start,FALLING);//set clk pin interrupt,this board interrupt0 is pin 2
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  start();
}
void start(){
  if(digitalRead(clk)==LOW){
  if(digitalRead(data)==LOW){
    angle+=10;
    }else angle-=10;
    if(angle>=180)angle=180;
    else if(angle<=10)angle=15;
    servo.write(angle);
    delay(150);
//    while(digitalRead(clk)==LOW);
}}
