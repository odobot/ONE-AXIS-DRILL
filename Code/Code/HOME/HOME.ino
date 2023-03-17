bool flag=true;
int limit;
attachInterrupt(digitalPinToInterrupt(limit),Home,LOW);// place in setup


void Home(){
  digitalRead(limit);
  while(limit==LOW )
  {
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
}
detachInterrupt(digitalPinToInterrupt(limit));// place in loop