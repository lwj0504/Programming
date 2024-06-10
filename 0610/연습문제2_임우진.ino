#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

int motion = 2;		// 모션 센서를 2번 핀으로 설정.
int light = 12;		// 사용할 LED를 13번 핀으로 설정.

void setup()
{
  lcd.begin(16,2);				// 16개의 셀과 2줄을 사용하도록 설정 
  lcd.clear();					// LCD 초기화.
  pinMode(motion, INPUT);	// 인체감지센서의 핀을 INPUT으로 설정.
  pinMode(light, OUTPUT);	// LED의 핀을 OUTPUT으로 설정.
  Serial.begin(9600);		// 시리얼 통신 속도 설정.
}

void loop()
{
  int sensor = digitalRead(motion);		// 적외선 인체감지 센서에서 값을 읽음.
  Serial.println(sensor);				// 센서값을 시리얼 모니터에 출력.
  // 센서값이 HIGH일 경우 LED를 키고 LCD에 Welcome! 출력.
  if (sensor == HIGH) {
  	digitalWrite(light, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Welcome!");		// 첫 줄에 메세지 출력
    delay(30000);	// 30초동안 대기.
  }
  // 30초동안 움직임이 없을 경우 LED를 끄고 LCD에 Goodbye! 출력.
  else {
  	digitalWrite(light, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Goodbye!");		// 첫 줄에 메세지 출력
  }
  delay(1000);
}