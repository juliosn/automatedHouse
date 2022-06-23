//Sens d' Blue led
int trigPin1 = 5; //port 1 
int echoPin1 = 4; //port 2

//Sens d' Red Led
int trigPin2 = 13; //port 7 
int echoPin2 = 15; //port 8


void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);

  pinMode(16, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  long duration1, distance1; 
  digitalWrite(trigPin1, HIGH); // Manda
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW); //-- Deslica o som --//
  duration1 = pulseIn(echoPin1, HIGH); //Receb  
  distance1 = (duration1 / 2) / 29.1; //Forml Som

//-- Verificar e testar Funcionamento --//
  Serial.print ( "Sensor1  ");
  Serial.print ( distance1);
  Serial.println("cm");

  if (distance1 < 11) {
    digitalWrite(16, HIGH);
  }
  else {
    digitalWrite(16, LOW);
  }
  delay(100);
  long duration2, distance2;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  Serial.print("Sensor2  ");
  Serial.print(distance2);
  Serial.println("cm");

  if (distance2 < 11) {
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(12, LOW);
  }
  

}
