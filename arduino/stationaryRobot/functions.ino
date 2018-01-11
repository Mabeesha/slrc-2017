
void releaseBall() {

  servoMotor.attach(PIN_SERVO);

  servoMotor.write(SERVO_RELEASE);
  delay(2000); // Let some time to turn and release the TT Ball
  servoMotor.write(SERVO_LOAD);
  delay(1000);
  servoMotor.detach();

}

void motorStop() {

  digitalWrite(PIN_MA, HIGH);
  digitalWrite(PIN_MB, LOW);

  /*digitalWrite(PIN_MA, LOW);
    digitalWrite(PIN_MB, HIGH);*/
}

void shootBall(int color) {

  motorOn(color);
  
  delay(del[color]);
  //------------------------------------------------------------------- Release

  servoMotor.attach(PIN_SERVO);

  servoMotor.write(SERVO_RELEASE);
  delay(2000); // Let some time to turn and release the TT Ball
  servoMotor.write(SERVO_LOAD);
  //--------------------------------------------------------------------

  motorOff();

  motorStop();
  analogWrite(PIN_SPINNER, 100);

  delay(1000);
  servoMotor.detach();
  motorOff();
}



void processColor(char c) {

  if (c == 'r') {
    Serial.println(">> Target : Red Box");
    digitalWrite(PIN_R, HIGH);

    moveRobot(x[RED_BOX], y[RED_BOX]);
    Serial.println(">> Shooting : Red Box");
    shootBall(RED_BOX);

    // Reply as done
    writeMobile("d");
    Serial.println(">> Done");

  } else if (c == 'g') {
    Serial.println(">> Target : Green Box");
    digitalWrite(PIN_G, HIGH);

    moveRobot(x[GREEN_BOX], y[GREEN_BOX]);
    Serial.println(">> Shooting : Green Box");
    shootBall(GREEN_BOX);

    // Reply as done
    writeMobile("d");
    Serial.println(">> Done");

  } else if (c == 'b') {
    Serial.println(">> Target : Blue Box");
    digitalWrite(PIN_B, HIGH);

    moveRobot(x[BLUE_BOX], y[BLUE_BOX]);
    Serial.println(">> Shooting : Blue Box");
    shootBall(DEF);

    // Reply as done
    writeMobile("d");
    Serial.println(">> Done");
  }

  digitalWrite(PIN_R, LOW);
  digitalWrite(PIN_G, LOW);
  digitalWrite(PIN_B, LOW);
}

void motorOn(int color) {
  digitalWrite(PIN_MA, LOW);
  digitalWrite(PIN_MB, HIGH);
  analogWrite(PIN_SPINNER, s[color]);
  Serial.println(s[color]);

}

void motorOff() {
  analogWrite(PIN_SPINNER, 0);
}



