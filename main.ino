#include <SoftwareSerial.h> // Knihovna pro komunikaci s Bluetooth modulem

// Definuj pinové číslo pro komunikaci s Bluetooth modulem
const int bluetoothTx = 2; // Připojeno k RX modulu
const int bluetoothRx = 3; // Připojeno k TX modulu

// Definuj SoftwareSerial objekt pro komunikaci s Bluetooth modulem
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// Definuj pinové číslo pro řízení jednotlivých motorů
const int motor1PWM = 5; // PWM pin pro motor 1
const int motor1Dir = 4; // Směrový pin pro motor 1
const int motor2PWM = 6; // PWM pin pro motor 2
const int motor2Dir = 7; // Směrový pin pro motor 2
const int motor3PWM = 9; // PWM pin pro motor 3
const int motor3Dir = 8; // Směrový pin pro motor 3
const int motor4PWM = 11; // PWM pin pro motor 4
const int motor4Dir = 10; // Směrový pin pro motor 4

void setup() {
  // Nastaví rychlost komunikace s Bluetooth modulem
  bluetooth.begin(9600);

  // Nastaví pinové režimy pro řízení motorů
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1Dir, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2Dir, OUTPUT);
  pinMode(motor3PWM, OUTPUT);
  pinMode(motor3Dir, OUTPUT);
  pinMode(motor4PWM, OUTPUT);
  pinMode(motor4Dir, OUTPUT);
}

void loop() {
  // Pokud je něco k dispozici k přečtení z Bluetooth modulu
  if (bluetooth.available()) {
    char receivedChar = bluetooth.read(); // Přečte příchozí znak

    // Ovládání motorů podle přijatých příkazů
    switch (receivedChar) {
      case 'F': // Jede dopředu
        moveForward();
        break;
      case 'B': // Jede dozadu
        moveBackward();
        break;
      case 'L': // Otáčí se doleva
        turnLeft();
        break;
      case 'R': // Otáčí se doprava
        turnRight();
        break;
      case 'S': // Stojí
        stopMotors();
        break;
    }
  }
}

// Funkce pro pohyb dopředu
void moveForward() {
  digitalWrite(motor1Dir, HIGH);
  analogWrite(motor1PWM, 255);
  digitalWrite(motor2Dir, HIGH);
  analogWrite(motor2PWM, 255);
  digitalWrite(motor3Dir, HIGH);
  analogWrite(motor3PWM, 255);
  digitalWrite(motor4Dir, HIGH);
  analogWrite(motor4PWM, 255);
}

// Funkce pro pohyb dozadu
void moveBackward() {
  digitalWrite(motor1Dir, LOW);
  analogWrite(motor1PWM, 255);
  digitalWrite(motor2Dir, LOW);
  analogWrite(motor2PWM, 255);
  digitalWrite(motor3Dir, LOW);
  analogWrite(motor3PWM, 255);
  digitalWrite(motor4Dir, LOW);
  analogWrite(motor4PWM, 255);
}

// Funkce pro otočení doleva
void turnLeft() {
  digitalWrite(motor1Dir, HIGH);
  analogWrite(motor1PWM, 255);
  digitalWrite(motor2Dir, LOW);
  analogWrite(motor2PWM, 255);
  digitalWrite(motor3Dir, HIGH);
  analogWrite(motor3PWM, 255);
  digitalWrite(motor4Dir, LOW);
  analogWrite(motor4PWM, 255);
}

// Funkce pro otočení doprava
void turnRight() {
  digitalWrite(motor1Dir, LOW);
  analogWrite(motor1PWM, 255);
  digitalWrite(motor2Dir, HIGH);
  analogWrite(motor2PWM, 255);
  digitalWrite(motor3Dir, LOW);
  analogWrite(motor3PWM, 255);
  digitalWrite(motor4Dir, HIGH);
  analogWrite(motor4PWM, 255);
}

// Funkce pro zastavení motorů
void stopMotors() {
  digitalWrite(motor1PWM, LOW);
  digitalWrite(motor2PWM, LOW);
  digitalWrite(motor3PWM, LOW);
  digitalWrite(motor4PWM, LOW);
}

