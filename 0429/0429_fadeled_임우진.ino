int ledPin = 5;			// 아날로그 핀 번호 설정
int brightness = 0;		// LED 밝기
int fadeAmount = 1;		// LED fade할 포인트 수

// 코드 실행시 한번 실행:
void setup()
{
  // 핀 번호 5를 출력으로 선언
  pinMode(ledPin, OUTPUT);
}

// 반복 구문:
void loop()
{
  // 아날로그 핀 번호 9 세팅
  analogWrite(ledPin, brightness);
  
  // 반복하면서 다음 밝기 변경
  brightness = brightness + fadeAmount;
  
  //fade 끝에서 fade 방향을 반대로
  if (brightness <= 0 || brightness >= 255)	{
    fadeAmount = -fadeAmount;
  }
  // 30 밀리초 기다리기
  delay(30);
}