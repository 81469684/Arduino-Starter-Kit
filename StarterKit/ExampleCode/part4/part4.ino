/*part4  USE PIR CONTROL Active buzzer and  Rled
 If someone passing from the front, the Active buzzer and Rled will turn */
int pir    = 3;// The digital 3 pin,read PIR
int buzzer = 4;// The digital 4 pin,driving the Active buzzer
int Rled   = 5;// The digital 5 pin,driving the Rled;
void setup() {
  pinMode(pir,INPUT);// initialize the PIR pin as an input.
  pinMode(buzzer,OUTPUT);// initialize the buzzer pin as an output.
  pinMode(Rled,OUTPUT);// initialize the Rled pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  if(digitalRead(pir)==HIGH){ 
    digitalWrite(buzzer,HIGH);
    digitalWrite(Rled,HIGH);
    delay(2000);// wait for 2000 microsecond
    digitalWrite(buzzer,LOW); //turn off the buzzer
    digitalWrite(Rled,LOW); //turn off the Rled
 } }

