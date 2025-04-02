#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#define led 11
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup(){
  pinMode(led,OUTPUT);
Wire.begin();
Serial.begin(38400);
Serial.println("MPU Baslatiliyor");
mpu.initialize();
Serial.println(mpu.testConnection() ? "Baglandi" : "Baglanti Hatali");
  }

void loop(){
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
Serial.println(ax);
analogWrite(led,map(ax,20000,-20000,255,0));
delay(50);

}

