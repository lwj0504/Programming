int redPin = 2;		// 핀 번호 설정
int yellowPin = 8;
int greenPin = 13;

// 이 코드는 실행 시 한번만 실행한다.
// 세팅하는곳
void setup()
{
  // LED를 출력모드로 설정
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
  // 빨강 LED
  digitalWrite(redPin, HIGH); // redPin을 HIGH로 출력하라.
  delay(1000); // 1초 기다리기
  digitalWrite(redPin, LOW); // redPin을 LOW로 출력하라.
  delay(1000); // 1초 기다리기
  
  // 노랑 LED
  digitalWrite(yellowPin, HIGH); // yellowPin을 HIGH로 출력하라.
  delay(1000); // 1초 기다리기
  digitalWrite(yellowPin, LOW); // yellowPin을 LOW로 출력하라.
  delay(1000); // 1초 기다리기
  
  // 초록 LED
  digitalWrite(greenPin, HIGH); // greenPin을 HIGH로 출력하라.
  delay(1000); // 1초 기다리기
  digitalWrite(greenPin, LOW); // greenPin을 LOW로 출력하라.
  delay(1000); // 1초 기다리기
}