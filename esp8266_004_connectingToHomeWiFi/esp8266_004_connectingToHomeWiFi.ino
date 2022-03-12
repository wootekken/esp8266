/*
  ESP8266WiFi.h  
  => File link : https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/src/ESP8266WiFi.h
*/

#include <ESP8266WiFi.h>  // WiFi 라이브러리

#define HOME_SSID   "KT_GiGA_5481"  // 우리집 WiFi 이름
#define HOME_PWD    "edb24zb726"      // 우리집 WiFi 비밀번호

void setup() {
  Serial.begin(115200);             // 시리얼 통신준비
  WiFi.begin(HOME_SSID, HOME_PWD);  // WiFi 통신 연결시작

  while(WiFi.status() != WL_CONNECTED) { // WiFi통신 연결이 잘 되었나?
    delay(1000);
    Serial.print(".");  // WiFi통신 연결이 완료될 때까지 점(.) 찍기
  }
  Serial.println("Connected!");
  Serial.print("your ip: ");
  Serial.println(WiFi.localIP()); // WiFi 연결완료 후, 로컬 ip출력하기
}

void loop() {

}
