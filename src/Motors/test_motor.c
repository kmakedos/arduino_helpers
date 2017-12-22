#define MOTOR_A_LEFT 2
#define MOTOR_A_RIGHT 3
#define MOTOR_B_LEFT 4
#define MOTOR_B_RIGHT 5

int motorA[2];
int motorB[2];

void move_simple(int motor[], size_t direction, int msec){
  digitalWrite(motor[direction], HIGH);
  delay(msec);
  digitalWrite(motor[direction], LOW);
  delay(msec);
}

void move_speed(int motor[], size_t direction, int msec, int speed){
  analogWrite(motor[direction], speed);
  delay(msec);
  analogWrite(motor[direction], LOW);
}


void reset(){
  digitalWrite(MOTOR_A_LEFT, LOW);
  digitalWrite(MOTOR_A_RIGHT, LOW);
  digitalWrite(MOTOR_B_LEFT, LOW);
  digitalWrite(MOTOR_B_RIGHT, LOW);
}

void setup() {
  motorA[0] = MOTOR_A_LEFT;
  motorA[1] = MOTOR_A_RIGHT;
  motorB[0] = MOTOR_B_LEFT;
  motorB[1] = MOTOR_B_RIGHT;
  for (size_t i =0 ; i < 2; i++){
    pinMode(motorA[i], OUTPUT);
    pinMode(motorB[i], OUTPUT);
  }
  reset();
}


void loop() {
  move_speed(motorA, 0, 20, 128);
  move_speed(motorA, 1, 20, 255);
}
