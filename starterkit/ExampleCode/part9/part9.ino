/* Part9 USE IRreceive and IR remote control motor fan speed and Displayed value of speed on the segment code */
#include "IRremote.h"//load IRremote library
#include "TM1637.h"//load Segment display library
#define CLK 4//pins definitions clk  for TM1637
#define DIO 5//pins definitions dio  for TM1637
TM1637 tm1637(CLK,DIO);//get Segment display controler
int motor=6;  //The digital 6 pin driver motor fan;must pwm pin of this board (3,5,6,9,10,11)
IRrecv ir(A5);//an instance of the IR receiver object,A5 is IRreceive pin(can be other);
decode_results result; // container for received IR codes
long int codes[12]=             // this array is used to store infrared codes
{16738455
,16724175
,16718055
,16743045
,16716015
,16726215
//0 1 2 3 4 5    
,16734885
,16728765
,16730805
,16732845
// 6 7 8 9
,16769055 //-
,16754775 //+
}; 
void setup(){
        tm1637.init();
	tm1637.set(BRIGHT_TYPICAL);
	ir.enableIRIn();//enable IR Recive
        Serial.begin(9600);
}
int speed=0;//init speed value
void loop(){
if(ir.decode(&result)){
 Serial.println(result.value);
        int count=-1;//init the begin value
         while(++count<12){
         if(result.value==codes[count]){//if  IR  remote send 0-9;+,-
         if(count<10){speed=count;}//IR  remote send 0-9
         else if(count==10){speed--;}// IR  remote send "-",speed-1
         else if(count==11){speed++;}// IR  remote send "+",speed+1
         break;
        }
       }
        ir.resume(); // resume receiver
	if(speed<0)speed=0;
        else if(speed>9)speed=9;
        //Starting Current is small, you can dial it with the hand motor fan
         //when arduino work Current is long time bigger than 40ma ,arduino will reset;
        analogWrite(motor,speed*28);//value 0-255
        tm1637.clearDisplay();
        tm1637.display(3,speed);  
      }

        tm1637.display(3,speed);  
  
}

