#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <AutoPID.h>

//motor pins where A and B are different directions for the same motor
#define MotorPin1A 1
#define MotorPin1B 2
#define MotorPin2A 3
#define MotorPin2B 4
#define MotorPin3A 7
#define MotorPin3B 8
#define MotorPin4A 5
#define MotorPin4B 6
//no encoders connected
#define ReceiverPin1 23
#define ReceiverPin2 13
#define ReceiverPin3 14
//pid settings and gains
#define OUTPUT_MIN 0
#define OUTPUT_MAX 255
#define KP .1
#define KI 0
#define KD 0

//deadzone for receiver value
const int deadzone = 20;

//PID IO and Setpoint variables
int Input = 0
int Output = 0
int Setpoint = 0

// Set the delay between fresh samples
uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;
//IMU object
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);


void setup() {
  Serial.begin(115200);
  
  pinMode(ReceiverPin1, INPUT);
  pinMode(ReceiverPin2, INPUT);
  pinMode(ReceiverPin3, INPUT);
  pinMode(MotorPin1A, OUTPUT);
  pinMode(MotorPin1B, OUTPUT);
  pinMode(MotorPin2A, OUTPUT);
  pinMode(MotorPin2B, OUTPUT);
  pinMode(MotorPin3A, OUTPUT);
  pinMode(MotorPin3B, OUTPUT);
  pinMode(MotorPin4A, OUTPUT);
  pinMode(MotorPin4B, OUTPUT);

  digitalWrite(MotorPin1A, LOW);
  digitalWrite(MotorPin1B, LOW);
  digitalWrite(MotorPin2A, LOW);
  digitalWrite(MotorPin2B, LOW);
  digitalWrite(MotorPin3A, LOW);
  digitalWrite(MotorPin3B, LOW);
  digitalWrite(MotorPin4A, LOW);
  digitalWrite(MotorPin4B, LOW);
  
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }
  bno.setExtCrystalUse(true);
  
  //define I/O variables and settings!
  AutoPID LegPID = AutoPID(Input, Setpoint, Output, OUTPUT_MIN , OUTPUT_MAX, KP, KI, KD);
  LegPID.
  
}

void loop() {
  //gather and print IMU data with given calibration values and delay
  sensors_event_t orientationData;
  bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  printEvent(&orientationData);
  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  delay(BNO055_SAMPLERATE_DELAY_MS);
  
  //convert reciever input to PWM value
  int Ch1=pulseIn(ReceiverPin1,HIGH,25000);
  int Ch2=pulseIn(ReceiverPin2,HIGH,25000);
  int Ch3=pulseIn(ReceiverPin3,HIGH,25000);
  Ch1=pulseToPWM(Ch1);
  Ch2=pulseToPWM(Ch2);
  Ch3=pulseToPWM(Ch3);
  //print test
  //Serial.println("Receiver Value: ");
  //Serial.println(Ch1);
  
  //leg movement cycle test
//  while(Ch1>254){
//    digitalWrite(MotorPin1A, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin1A, LOW);
//    digitalWrite(MotorPin1B, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin1B, LOW);
//    digitalWrite(MotorPin2A, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin2A, LOW);
//    digitalWrite(MotorPin2B, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin2B, LOW);
//    digitalWrite(MotorPin3A, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin3A, LOW);
//    digitalWrite(MotorPin3B, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin3B, LOW);
//    digitalWrite(MotorPin4A, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin4A, LOW);
//    digitalWrite(MotorPin4B, HIGH);
//    delay(3000);
//    digitalWrite(MotorPin4B, LOW);
//    delay(5000);
//  }

  
}

int pulseToPWM(int pulse){
  if (pulse>1000){
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255,255);  
  }else{
    pulse=0;  
  }
  if(abs(pulse)<= deadzone){
    pulse=0;
  }
  return pulse;
}

void printEvent(sensors_event_t* event) {
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  if (event->type == SENSOR_TYPE_ACCELEROMETER) {
    Serial.print("Accl:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_ORIENTATION) {
    Serial.print("Orient:");
    x = event->orientation.x;
    y = event->orientation.y;
    z = event->orientation.z;
  }
  else if (event->type == SENSOR_TYPE_MAGNETIC_FIELD) {
    Serial.print("Mag:");
    x = event->magnetic.x;
    y = event->magnetic.y;
    z = event->magnetic.z;
  }
  else if (event->type == SENSOR_TYPE_GYROSCOPE) {
    Serial.print("Gyro:");
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_ROTATION_VECTOR) {
    Serial.print("Rot:");
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_LINEAR_ACCELERATION) {
    Serial.print("Linear:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else {
    Serial.print("Unk:");
  }

  Serial.print("\tx= ");
  Serial.print(x);
  Serial.print(" |\ty= ");
  Serial.print(y);
  Serial.print(" |\tz= ");
  Serial.println(z);
}

void levelingWithPID(){
    
}
