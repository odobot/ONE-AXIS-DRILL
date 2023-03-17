/*LMS1V = digitalRead(LMS1);
  if (LMS1 == HIGH) {
    VIBRATION();
    FORCE();
    Serial.print("TEMPERATURE:");
    Serial.println(mlx.readObjectTempC());
    digitalWrite(dirPin, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN, SPEED);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  } else {
    VIBRATION();
    FORCE();
    Serial.print("TEMPERATURE:");
    Serial.println(mlx.readObjectTempC());
    digitalWrite(dirPin, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN, SPEED);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }*/
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
