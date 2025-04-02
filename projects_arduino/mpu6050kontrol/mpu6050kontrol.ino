#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
MPU6050 ivme;
int16_t ax, ay, az;
int16_t gx, gy, gz;


void setup() {
        Wire.begin();
    Serial.begin(38400);
    ivme.initialize();
    Serial.println(ivme.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
    Serial.println("Updating internal sensor offsets...");
}

void loop() {
   delay(10);
    ivme.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

        Serial.print("a/g:\t");
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.println("\t");
        //Serial.print(gx); Serial.print("\t");
        //Serial.print(gy); Serial.print("\t");
       // Serial.println(gz);
}
