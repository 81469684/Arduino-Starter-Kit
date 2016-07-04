/*part2  USE BUTTON CONTROL RGB LED
  Press the button first, led lights, then press the button led will chance */
int Rled = 4;// The digital 4 pin,driving RLED
int Gled = 5;// The digital 5 pin,driving GLED
int Bled = 6;// The digital 6 pin,driving BLED
int button = 3;// The digital 3 pin,read the button
int LedStatus=0;
void setup() {
  pinMode(Rled, OUTPUT);// initialize the RLED pin as an output.
  pinMode(Gled, OUTPUT);// initialize the GLED pin as an output.
  pinMode(Bled, OUTPUT);// initialize the BLED pin as an output.
  pinMode(button, INPUT);// initialize the BUTTON pin as an input.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  if(digitalRead(button)==HIGH){ //when Press button   
    if(++LedStatus>=4)LedStatus=0;//check led status
    switch(LedStatus){
    case 0:
          digitalWrite(Rled,LOW);
          digitalWrite(Gled,LOW);
          digitalWrite(Bled,LOW);
          break;
    case 1:
          digitalWrite(Rled,HIGH);
          digitalWrite(Gled,LOW);
          digitalWrite(Bled,LOW);
          break;          
    case 2:
          digitalWrite(Rled,LOW);
          digitalWrite(Gled,HIGH);
          digitalWrite(Bled,LOW);
          break;
     case 3:
          digitalWrite(Rled,LOW);
          digitalWrite(Gled,LOW);
          digitalWrite(Bled,HIGH);
          break;         
  }
    while(digitalRead(button)==HIGH);//wait button release
    delay(200);// wait for 200 microsecond,Avoid pressing the button and read many times in this very short time

                                 }
}

