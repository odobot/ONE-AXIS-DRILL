#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int IN1 = 10;
int IN2 = 11;
int EN = 12;
int LMS1 = 7;
int LMS2 = 6;
int SPEED = 255;
int TIME = 15000;
bool flag=true;
int limit;

// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 1600
//Home();

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(limit),Home,LOW);
  while (!Serial)
    ;
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. check wiring.");
    while (1)
      ;
  };
}

void loop() {
  detachInterrupt(digitalPinToInterrupt(limit));
  Serial.println(mlx.readObjectTempC());
  digitalWrite(dirPin, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //analogWrite(EN, SPEED);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < 20 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  delay(1000);
}
void Home() {
  digitalRead(limit);
  while (limit == LOW) {
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
}
/*void HOME() {
  digitalRead(LMS1);
  if (LMS1 == HIGH) {
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  } else () {
      digitalWrite(dirPin, LOW);
      while (home < 1) {
        if (LMS1 != HIGH) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          home == 0;
        }
        else{
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          home == 1;
        }
      }
    }
}*/
