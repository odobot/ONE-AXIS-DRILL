#include <Adafruit_MLX90614.h>
#include <Arduino.h>
#include "HX711.h"

int pin = 21;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int IN1 = 10;
int IN2 = 11;
int EN = 12;
int LMS1 = 7;
int LMS2 = 6;
int SPEED = 255;
int TIME = 15000;
int FC1 = A1;
int FC2 = A2;
int VB = A0;
int VVB, VFC1, VFC2, LMS1V, LMS2V, i;
float Average;
// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 1600

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

HX711 scale;

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. check wiring.");
    while (1)
      ;
  };
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());  // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));  // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));  // print the average of 5 readings from the ADC minus the tare weight (not set yet)

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight (not set) divided
                                          // by the SCALE parameter (not set yet)

  scale.set_scale(210.289);
  //scale.set_scale(210.289);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();  // reset the scale to 0

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());  // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));  // print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));  // print the average of 5 readings from the ADC minus the tare weight, set with tare()

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight, divided
                                          // by the SCALE parameter set with set_scale

  Serial.println("Readings:");
  //attachInterrupt(digitalPinToInterrupt(21), Go_Home, CHANGE);
}

/*void Go_Home() {
  for (i=0; i<=100000; i++) {
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
    if (digitalRead(20) == 1)
    {
      break;
    }
  }
}*/

void loop() {
  //Serial.print("TEMPERATURE:");
  //Serial.print(" , ");
  //Serial.print(scale.get_units(10), 5);// LOAD
  Serial.print(" , ");
  Serial.println(mlx.readObjectTempC());// Temperature
  digitalWrite(dirPin, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN, SPEED);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
  //delay(1000);
  VIBRATION();
  LOAD();
}
void VIBRATION() {
  VVB = analogRead(VB);
  //Serial.print("VIBRATION:");
  Serial.print(VVB);
  Serial.print(" , ");
}

void LOAD() {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
  Serial.print(scale.get_units(10), 5);
  Serial.print(" , ");
}
