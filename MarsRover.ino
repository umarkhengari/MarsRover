#include <ArduinoJson.h>
StaticJsonDocument<256> jsonCmdReceive;
StaticJsonDocument<256> jsonInfoSend;
StaticJsonDocument<512> jsonInfoHttp;


#include <INA219_WE.h>
#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>
#include <esp_now.h>

#include <battery_ctrl.h>
#include <config.h>
#include <motor_ctrl.h>
#include <wifi_ctrl.h>
#include <http_server.h>
#include <esp_now_ctrl.h>


void setup() {
  Serial.begin(115200);
  Wire.begin(S_SDA, S_SCL);
  while(!Serial) {}

  
  ina219_init();
  inaDataUpdate();
  Serial.println("Battery & Power Management Initialized");
  
  motor_pin_init();
  Serial.println("Motor Initialized");

  initWifi();
  Serial.println("Wi-Fi Initialized");
  
  initHttpWebServer();
  Serial.println("Web Server Initialized");

  initEspNow();
  Serial.println("ESP Now Initialized");

}
float speed = 0;
void loop() {
    float new_speed = Serial.parseFloat(SKIP_ALL, '\n');
    if (new_speed) {
      speed = new_speed;
    }
    Serial.print("Speed configured: ");
    Serial.println(speed);
    channel_A_Ctrl(speed);
    channel_B_Ctrl(speed);
    delay(1000);
}