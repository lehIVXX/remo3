
// TimerOne library: https://code.google.com/p/arduino-timerone/downloads/list

// Hardware setup:
// BT module   Arduino
// GND ------- GND
// VCC ------- 5V
// TX-O ------ pin0
// RX-I ------ pin1

// square wave output: Arduino pin 9

#define bluetooth Serial
#define slave1 Serial1

//#include "TimerOne.h"

char cmd[100];
int cmdIndex;

//const int Nval=3;
int val[2];
//char valNum[5]={'a'}
const int pwmA =13;
void debug(String st) {
  bluetooth.print("debug " + st + "\n");
}

void exeCmd() {  
//for(int i=0; i<Nval;i++){
  if(cmd[0]=='a' && cmd[1]==' ') {        
  val[0]= atoi(cmd+2);   
  debug((String)"A="+val[0]);        
    // Timer1.pwm(9, duty*10.24, 1000000/freq);
   // slave1.write("a "+val[0]);
   analogWrite(13,val[0]);
   }
    
  if(cmd[0]=='b' && cmd[1]==' ') {
    val[1]= atoi(cmd+2);
  //  Timer1.pwm(9, duty*10.24, 1000000/freq);  // period[us] = 1000000 / freq[Hz]
    debug((String)"B="+val[1]);
    analogWrite(12,val[1]);
  }
        
        
        
        
  }


void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(13,LOW);
   digitalWrite(12,LOW;     
  delay(500); // wait for bluetooth module to start
  bluetooth.begin(115200); // Bluetooth default baud is 115200
  cmdIndex = 0;
//  Timer1.initialize();
 // slave1.begin(9600);
//  duty = 10; // 10%
//  freq = 20; // 20 Hz
//  Timer1.start();
//  Timer1.pwm(9, duty*10.24, 1000000/freq);
}

void loop() {
  
  if(bluetooth.available() > 0) {   
   char c = (char)bluetooth.read();        
  // slave1.write(c);           
     if(c=='\n') { 
      cmd[cmdIndex] = 0;
      exeCmd();  // execute the command
      cmdIndex = 0; // reset the cmdIndex
    } else {      
      cmd[cmdIndex] = c;
      if(cmdIndex<99) cmdIndex++;
    }
}
}
