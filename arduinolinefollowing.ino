  int vSpeed = 110;        // MAX 255
  int turn_speed = 230;    // MAX 255 
  int turn_delay = 10;
  
//L293 Connection   
  const int motorA1      = 3;  
  const int motorA2      = 4; 
  const int motorAspeed  = 5;
  const int motorB1      = 7; 
  const int motorB2      = 8; 
  const int motorBspeed  =6;

//Sensor Connection
  const int left_sensor_pin =9;
  const int right_sensor_pin =10;

  
  
  int left_sensor_state;
  int right_sensor_state;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

  delay(3000);
  
}

void loop() {
  

  


left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);

if(right_sensor_state == HIGH && left_sensor_state == LOW)
{
  Serial.println("turning right");

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
  
  }
if(right_sensor_state == LOW && left_sensor_state == HIGH)
{
  Serial.println("turning left");
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state == LOW && left_sensor_state == LOW)
{
  Serial.println("going forward");

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  
  }

if(right_sensor_state == HIGH && left_sensor_state == HIGH)
{ 
  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
  while(true){
  
 }
  }

 
}
