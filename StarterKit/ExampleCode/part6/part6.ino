/*part6  USE Soil moisture sensor CONTROL Relay
 According to the intensity of light motor speed control */
int soil  = A5;// The analog A5 pin,read Soil moisture
int relay = 4; // The digital 4 pin,driving the Relay
void setup() {
  pinMode(soil,INPUT_PULLUP);// initialize the soil pin as an input.
  pinMode(relay,OUTPUT);// initialize the relay pin as an output.
  Serial.begin(9600);//Open Serial out
}                                                                                                                                                                                                                                                                                                                                                                                                                       
void loop() {
  //Soil moisture sensor AOut pin ,The smaller the soil resistance, the higher the output voltage
  //Soil moisture sensor DOut pin,if AOut>2.5V,DOut=5V;if AOut<2.5V,DOut=0V;
    int value=analogRead(soil);//Don't use pure water test
    Serial.println(value);//print value to PC
    if(value<500){//set the default value ,you can set it then more or less to do something
    digitalWrite(relay,HIGH);//turn on the relay
    }else digitalWrite(relay,LOW);//turn off the relay
}

