void setup(){
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop(){
  analogWrite(11, 255);
  analogWrite(10, 0);
  analogWrite(9, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(11, 255);
  analogWrite(10, 255);
  analogWrite(9, 102);
  delay(1000); // Wait for 1000 millisecond(s)
}

