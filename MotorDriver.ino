/*************************************************************
Motor Shield 2-Channel DC Motor for Arduino Motor Shield V3
by Ramanathan Sabapathy (ram.kshatriya@gmail.com)

*************************************************************/

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT);//Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
    //Setup Channel B
  pinMode(13, OUTPUT);//Initiates Motor Channel B pin
  pinMode(8, OUTPUT); //Initiates Brake Channel B pin
  
  //myservo.attach(5);
   Serial.begin(9600);
   Serial.print("Setup Completed\n");
}

void loop(){
  
  forward();
  wait(3000);
   
  if(surge())
  {  

    brake(HIGH);
    wait(1000);
    backward();

    wait(3000);
    brake(HIGH);

    wait(1000);
    turnRight();
  

    wait(3000);
    brake(HIGH);
  
    wait(1000);
  }
  
}

void forward(){
    //forward A full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  
    //forward B full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
  
  return;
}

void backward(){
     //backward A half speed
    digitalWrite(12, LOW); //Establishes backward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    //analogWrite(3, 123);   //Spins the motor on Channel A at half speed
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
    
    //backward B half speed
    digitalWrite(13, LOW); //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    //analogWrite(11, 123);   //Spins the motor on Channel B at half speed
    analogWrite(11, 255);   //Spins the motor on Channel B at full speed
    
    return;
}

void brake(boolean brake){
    digitalWrite(9, brake); //Eengage the Brake for Channel A
    digitalWrite(8, brake); //Eengage the Brake for Channel B
}

void turnLeft(){
    //left @ full speed
    digitalWrite(12, HIGH); //Establishes backward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    //analogWrite(3, 123);   //Spins the motor on Channel A at half speed
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, LOW); //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    //analogWrite(11, 123);   //Spins the motor on Channel B at half speed
    analogWrite(11, 255);   //Spins the motor on Channel B at full speed
    
    return;
}

void turnRight(){
    //right @ full speed
    digitalWrite(12, LOW); //Establishes backward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    //analogWrite(3, 123);   //Spins the motor on Channel A at half speed
    analogWrite(3, 255);   //Spins the motor on Channel A at full speed
    
    digitalWrite(13, HIGH); //Establishes backward direction of Channel A
    digitalWrite(8, LOW);   //Disengage the Brake for Channel A
    //analogWrite(11, 123);   //Spins the motor on Channel A at half speed
    analogWrite(11, 255);   //Spins the motor on Channel A at full speed
    
    return;
}

boolean surge(){
  int sensorValue1=analogRead(A0);
  int sensorValue2=analogRead(A1);
  
  if(sensorValue1 > 200 || sensorValue2 > 200)
  {
    //print(surge);
    return HIGH;
  }
  else
  {
    //print(no surge);
    return LOW;
  }
}

void wait(int delay_ms){
  delay(delay_ms);
  return;
}


