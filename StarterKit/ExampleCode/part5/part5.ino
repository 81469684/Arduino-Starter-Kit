/*part5  USE Photodiode CONTROL Rled BRIGHTNESS
 Built-in photosensitive resistor (CDS), Brightness according to ambient light, Automatic Rled BRIGHTNESS. */
int photodiode= A5;// The analog A5 pin,read Photodiode
int Rled = 6;// The digital6 pin,driving the Rled ,the arduino uno pwm pin is(digital 3,5,6,9,10,11)
void setup() {
  pinMode(photodiode,INPUT_PULLUP);// initialize the photodiode pin as an input.
  pinMode(Rled,OUTPUT);// initialize the motor pin as an output.
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
    //photodiode modul AOut pin out analog value,The higher the external environment brightness, the smaller the value
    //photodiode modul DOut pin out digital value,if AOut>2.5V,Dout=5V,if AOut<2.5V,DOut=0V;
    int brightness=analogRead(photodiode)/4;//because the read  value is 0-1023,pwm out value is 0-255;
    analogWrite(Rled,brightness);//pwn-out control brightness of Rled
     }

