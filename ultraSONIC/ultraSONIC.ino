/*this code is used for ultrasonic sensor and it might be deployed to the traffic light project*/

const int trigPin = 7;
const int echoPin = 8;

void setup() {
 // initialize the ultrasonic
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
  // set the metric system first
  long duration, inches, cm;

// then set the code for ultrasonic sensor.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // set the duration by using the echoPin
  duration = pulseIn(echoPin, HIGH);

  // convert the time to distance(in metric system)
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimetres(duration);

  Serial.print(inches);
  Serial.print("inches, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds) {
  // Convert it from microsecond to inches
  return microseconds / 74 / 2;
}

long microsecondsToCentimetres(long microseconds) {
  // Convert it from microsecond to centimetres
  return microseconds / 29 / 2;
}
