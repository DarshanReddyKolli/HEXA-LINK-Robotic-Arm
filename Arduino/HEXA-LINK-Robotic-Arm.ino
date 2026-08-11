#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 4); // RX, TX
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// ================= SERVO CHANNELS =================
#define SERVO1 0  // BASE
#define SERVO2 1  // SHOULDER1
#define SERVO3 2  // SHOULDER2
#define SERVO4 3  // ELBOW1
#define SERVO5 4  // ELBOW2
#define SERVO6 5  // WRIST
#define SERVO7 6  // GRIPPER

// ================= SERVO LIMITS ===================
#define SERVOMIN 110
#define SERVOMAX 500

// ================= SPEED ==========================
int s1Vel = 15;
int s2Vel = 25;
int s4Vel = 20;
int s5Vel = 20;
int s6Vel = 15;
int s7Vel = 15;
int velG  = 25;

// ================= VARIABLES ======================
int index = 0;
int s1Act,s2Act,s4Act,s5Act,s6Act,s7Act;   // "Act" = current/target value
int s1Ant,s2Ant,s4Ant,s5Ant,s6Ant,s7Ant;   // "Ant" = previous value

int s1[50],s2[50],s4[50],s5[50],s6[50],s7[50];

String bt, btS;

// ================= FUNCTIONS ======================
int angleToPulse(int ang){
  return map(ang, 0, 180, SERVOMIN, SERVOMAX);
}

void moveServo(uint8_t ch, int from, int to, int spd){
  if(from > to){
    for(int i = from; i >= to; i--){
      pwm.setPWM(ch, 0, angleToPulse(i));
      delay(spd);
    }
  } else {
    for(int i = from; i <= to; i++){
      pwm.setPWM(ch, 0, angleToPulse(i));
      delay(spd);
    }
  }
}

// ================= SETUP ==========================
void setup() {
  Serial.begin(115200);
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(10);

  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(100);

  // Initial positions
  s1Ant = 90;
  s2Ant = 100;
  s4Ant = 115;
  s5Ant = 60;
  s6Ant = 90;
  s7Ant = 60;

  pwm.setPWM(SERVO1, 0, angleToPulse(s1Ant));
  pwm.setPWM(SERVO2, 0, angleToPulse(s2Ant));
  pwm.setPWM(SERVO3, 0, angleToPulse(180 - s2Ant));
  pwm.setPWM(SERVO4, 0, angleToPulse(s4Ant));
  pwm.setPWM(SERVO5, 0, angleToPulse(s5Ant));
  pwm.setPWM(SERVO6, 0, angleToPulse(s6Ant));
  pwm.setPWM(SERVO7, 0, angleToPulse(s7Ant));
}

// ================= LOOP ===========================
void loop() {

  if(Bluetooth.available()){
    bt = Bluetooth.readString();

    // -------- BASE --------
    if(bt.startsWith("s1")){
      s1Act = bt.substring(2).toInt();
      moveServo(SERVO1, s1Ant, s1Act, s1Vel);
      s1Ant = s1Act;
    }

    // -------- SHOULDER --------
    if(bt.startsWith("s2")){
      s2Act = bt.substring(2).toInt();
      for(int i = s2Ant; i != s2Act; (s2Ant < s2Act) ? i++ : i--){
        pwm.setPWM(SERVO2, 0, angleToPulse(i));
        pwm.setPWM(SERVO3, 0, angleToPulse(180 - i));
        delay(s2Vel);
        if(i == s2Act) break;
      }
      s2Ant = s2Act;
    }

    // -------- ELBOW1 --------
    if(bt.startsWith("s4")){
      s4Act = bt.substring(2).toInt();
      moveServo(SERVO4, s4Ant, s4Act, s4Vel);
      s4Ant = s4Act;
    }

    // -------- ELBOW2 --------
    if(bt.startsWith("s5")){
      s5Act = bt.substring(2).toInt();
      moveServo(SERVO5, s5Ant, s5Act, s5Vel);
      s5Ant = s5Act;
    }

    // -------- WRIST --------
    if(bt.startsWith("s6")){
      s6Act = bt.substring(2).toInt();
      moveServo(SERVO6, s6Ant, s6Act, s6Vel);
      s6Ant = s6Act;
    }

    // -------- GRIPPER --------
    if(bt.startsWith("s7")){
      s7Act = bt.substring(2).toInt();
      moveServo(SERVO7, s7Ant, s7Act, s7Vel);
      s7Ant = s7Act;
    }

    // -------- SAVE POSITION --------
    if(bt.startsWith("SAVE")){
      s1[index]=s1Ant; s2[index]=s2Ant; s4[index]=s4Ant;
      s5[index]=s5Ant; s6[index]=s6Ant; s7[index]=s7Ant;
      index++;
    }

    // -------- RESET --------
    if(bt.startsWith("RESET")){
      memset(s1,0,sizeof(s1));
      memset(s2,0,sizeof(s2));
      memset(s4,0,sizeof(s4));
      memset(s5,0,sizeof(s5));
      memset(s6,0,sizeof(s6));
      memset(s7,0,sizeof(s7));
      index = 0;
    }

    // -------- SPEED --------
    if(bt.startsWith("ss")){
      velG = bt.substring(2).toInt();
    }

    // -------- RUN (playback of saved sequence) --------
    if(bt.startsWith("RUN")){
      while(true){
        if(Bluetooth.available()){
          bt = Bluetooth.readString();
          if(bt.startsWith("RESET")) break;
          if(bt.startsWith("PAUSE")){
            while(true){
              if(Bluetooth.available()){
                bt = Bluetooth.readString();
                if(bt.startsWith("RUN")) break;
                if(bt.startsWith("RESET")) return;
              }
            }
          }
        }

        for(int i=0;i<index-1;i++){
          moveServo(SERVO1, s1[i], s1[i+1], velG);
          moveServo(SERVO2, s2[i], s2[i+1], velG);
          pwm.setPWM(SERVO3, 0, angleToPulse(180 - s2[i+1]));
          moveServo(SERVO4, s4[i], s4[i+1], velG);
          moveServo(SERVO5, s5[i], s5[i+1], velG);
          moveServo(SERVO6, s6[i], s6[i+1], velG);
          moveServo(SERVO7, s7[i], s7[i+1], velG);
        }
      }
    }
  }
}
