#include <SoftwareSerial.h>
SoftwareSerial myserial(7, 8);     
//download"bluetooth controller" form google play 
//insert the variables(a,b,c,d) in the code in the app at the Set key tap
 
int motor1a = 3; // pin number controlling motor one anticlockwise
int motor1c = 5;  //pin number controlling motor one clockwise
int motor2a =6  //pin number controlling motor two anticlockwise
int motor2c =9; //pin number controlling motor two clockwise
 
 
void setup()                    // run once, when the sketch starts
{
Serial.begin(57600);// opens the serial port
  myserial.begin(9600); //opens the l
  pinMode(motor1a, OUTPUT);
  pinMode(motor1c, OUTPUT);
  pinMode(motor2c, OUTPUT);
  pinMode(motor2a, OUTPUT);
 
}
 
void loop()
{Serial.println("action=");
  myserial.println(" ON"); // test the bluetooth's connecton
  if (myserial.available()>0) {
    char b = myserial.read(); //read the input
    Serial.write(b);
    if (b == 'a') {       //in case of 'a' motor one moves anticlockwise
     digitalWrite(motor1a,HIGH);
    }
    if (b == 'b') { //in case of 'b' motor one moves clockwise
    digitalWrite(motor1c,LOW); // put motor one anticlockwise off
      digitalWrite(motor1a,HIGH);//in case of 'a' motor one moves clockwise
    }
    if (b == 'c') { //
      digitalWrite(motor2a,HIGH); //in case of 'c' motor two moves anticlockwise
      dwigitalWrite(motor1a,LOW);// put motor one clockwise off
    }
    if (b == 'd') {  
      digitalWrite(motor2a,LOW); // put motor two anticlockwise off
      digitalWrite(motor1a,HIGH);//in case of 'd' motor two moves clockwise
 
    }
    if (b == 'e') { //incase of 'e' puts all motor rotations off
    digitalWrite(motor2a,LOW); 
    digitalWrite(motor2c,LOW);
    digitalWrite(motor1c,LOW);
 digitalWrite(motor1a,LOW);
    }
  
  }
 
}
