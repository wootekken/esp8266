#include <ESP8266WiFi.h>  // WiFi 라이브러리

void setup() {
  Serial.begin(115200);             // 시리얼 통신준비
  int numberOfNetworks = WiFi.scanNetworks(); // 주변 WiFi 신호 검색 개수반환

  for(int i = 0; i < numberOfNetworks; i++) {
    Serial.print("WiFi name: ");
    Serial.println(WiFi.SSID(i)); // WiFi 이름 출력
    Serial.print("Signal strength: ");
    Serial.println(WiFi.RSSI(i)); // WiFi 신호 강도
    Serial.println("----------------------------");
  }
}

void loop() {

}
