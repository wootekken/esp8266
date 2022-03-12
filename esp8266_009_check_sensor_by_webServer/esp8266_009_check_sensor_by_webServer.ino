#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

#define HOME_SSID   "KT_GiGA_1234"  // 우리집 WiFi 이름
#define HOME_PWD    "12345678"    // 우리집 WiFi 비밀번호
#define POT         A0              // 가변저항 센서 연결핀

ESP8266WebServer server(80);  // HTTP 기본 포트인 80설정

void setup() {
  Serial.begin(115200);
  WiFi.begin(HOME_SSID, HOME_PWD);  // WiFi에 접속하기
 
  while (WiFi.status() != WL_CONNECTED) {  // WiFi 접속이 완료되었나?
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  // 로컬ip 출력
 
  server.on("/", check_sensor);    // 센서값 보기 함수
  server.begin();                   // 웹서버 시작하기
  Serial.println("Server listening");
}
 
void loop() {
  server.handleClient();        // HTTP 요청 처리하기
}
 
void check_sensor() {            // 루트 path요청에 실행되는 함수
  int sensor = analogRead(POT); // 가변저항 센서 값 읽기
  String s1 = String(sensor); // int to String
  server.send(200, "text/html", "s1: " + s1);
}
