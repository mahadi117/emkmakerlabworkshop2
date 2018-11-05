int ledPin = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
// reading the value of the IR sensor with analogRead function. 
// 0 - 5 volts will be represented in a range of 0-1023 
Serial.println(analogRead(A0));
delay(1000);
if(analogRead(A0) < 250)
digitalWrite(11,HIGH);
else
digitalWrite(11,LOW);
}
