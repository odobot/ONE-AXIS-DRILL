/*#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 1600
int IN1 = 10;
int IN2 = 11;
int EN = 12;
int SPEED = 47;
int TIME = 15000;
int i;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1)
      ;
  };
}

void loop() {
  Serial.print(mlx.readObjectTempC());
  // Set the spinning direction clockwise:
  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN, SPEED);
  delay(TIME);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(EN, SPEED);
  delay(TIME);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);
}
Serial.println(mlx.readObjectTempC());
delay(1000);

// Set the spinning direction counterclockwise:
digitalWrite(dirPin, LOW);

// Spin the stepper motor 1 revolution quickly:
for (int i = 0; i < stepsPerRevolution; i++) {
  // These four lines result in 1 step:
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(1000);
}

delay(1000);

// Set the spinning direction clockwise:
digitalWrite(dirPin, HIGH);

// Spin the stepper motor 5 revolutions fast:
for (int i = 0; i < 7 * stepsPerRevolution; i++) {
  // These four lines result in 1 step:
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
}

delay(1000);

// Set the spinning direction counterclockwise:
digitalWrite(dirPin, LOW);

// Spin the stepper motor 5 revolutions fast:
for (int i = 0; i < 7 * stepsPerRevolution; i++) {
  // These four lines result in 1 step:
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
}

delay(1000);
}
