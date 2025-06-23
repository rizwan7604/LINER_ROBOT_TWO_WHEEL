// IR Sensor Pins
#define LEFT_SENSOR 2
#define RIGHT_SENSOR 3

// Motor A (Left Motor)
#define ENA 5
#define IN1 8
#define IN2 9

// Motor B (Right Motor)
#define ENB 6
#define IN3 10
#define IN4 11

// Motor speed (0–255)
int motorSpeed = 100; // lower = slower

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
  delay(1000); // Wait for sensors to stabilize
}

void loop() {
  int left = digitalRead(LEFT_SENSOR);   // LOW = black line
  int right = digitalRead(RIGHT_SENSOR); // LOW = black line

  if (left == HIGH && right == HIGH) {
    stopMotors(); // Both on black line
  }
  else if (left == LOW && right == LOW) {
    moveForward(); // Both off line (white surface)
  }
  else if (left == HIGH && right == LOW) {
    turnRight();
  }
  else if (left == LOW && right == HIGH) {
    turnLeft();
  }
  else {
    stopMotors(); // Fallback
  }

  delay(50);
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, motorSpeed);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, 0);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
