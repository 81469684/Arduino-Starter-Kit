/*part3  USE Vibration sensors CONTROL Active buzzer
 Knock on the table, the buzzer will ring */
int vibration = 3;// The digital 3 pin,read Vibration sensors
int buzzer = 4;// The digital 4 pin,driving the Active buzzer
void setup() {
  pinMode(vibration,INPUT);// initialize the vibration pin as an input.
  pinMode(buzzer,OUTPUT);// initialize the buzzer pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  if(digitalRead(vibration)==HIGH){ 
    digitalWrite(buzzer,HIGH);//driver Passive buzzer must PWM,so analogWrite,200 is PWM value,max 1024
    delay(1000);// wait for 1000 microsecond
    digitalWrite(buzzer,LOW); //turn off the buzzer
 } }

