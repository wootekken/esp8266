#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

#define HOME_SSID   "KT_GiGA_5481"  // 우리집 WiFi 이름
#define HOME_PWD    "edb24zb726"      // 우리집 WiFi 비밀번호
#define LED_PIN     D13   // 내장 LED 핀번호

ESP8266WebServer server(80);  // HTTP 기본 포트인 80설정

bool ledState = LOW;  // led on,off 상태

void setup() {
  pinMode(LED_PIN, OUTPUT); // led 출력모드
  Serial.begin(115200);
  WiFi.begin(HOME_SSID, HOME_PWD);  // WiFi에 접속하기
 
  while (WiFi.status() != WL_CONNECTED) {  // WiFi 접속이 완료되었나?
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  // 로컬ip 출력
 
  server.on("/", helloFunction);    // 루트 path 요청에 실행할 함수 설정
  server.on("/on", ledOn);
  server.on("/off", ledOff);
  server.on("/toggle", ledToggle);
  server.begin();                   // 웹서버 시작하기
  Serial.println("Server listening");
}
 
void loop() {
  server.handleClient();        // HTTP 요청 처리하기
}
 
void helloFunction() {            // 루트 path요청에 실행되는 함수
  server.send(200, "text/html", "LED ON: /on <br> LED OFF: /off"); // Hello world 글자 응답
}

void ledOn() {
  ledState = HIGH;
  digitalWrite(LED_PIN, ledState);
  server.send(200, "text/plain", "LED is on");
}

void ledOff() {
  ledState = LOW;
  digitalWrite(LED_PIN, ledState);
  server.send(200, "text/plain", "LED is off");
}

void ledToggle() {
  ledState = !ledState; // 상태값 반전 시키기
  digitalWrite(LED_PIN, ledState);
  server.send(200, "text/plain", "LED is toggled");
}
