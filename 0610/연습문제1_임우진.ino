int water_pin = A0;		// 수분수위센서 A0에 연결
int outputpin = A5;		// 온도센서를 A5에 연결
int red_pin = 2;		// 빨간 LED를 2에 연결
int blue_pin = 3;		// 노란 LED를 3에 연결
int green_pin = 4;		// 초록 LED를 4에 연결

void setup()
{
  Serial.begin(9600);	// Serial monitor 구동
  
  pinMode(water_pin, INPUT);	// 수분수위센서를 입력으로 설정
  pinMode(red_pin, OUTPUT);		// LED를 출력으로 설정
  pinMode(blue_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
}

void loop()
{
  // 온도 센서가 가지고 오는 값을 저장
  int reading = analogRead(outputpin);
  
  // 섭씨 온도로 변환
  float voltage = reading * 5.0 / 1024.0;
  float celsiustemp = (voltage - 0.5) * 100;
  Serial.print(celsiustemp);
  Serial.println(" C");
  
  // 수분 센서가 가지고 오는 값을 저장
  int waterLevel = analogRead(water_pin);
  Serial.println(waterLevel);
  delay(500);
  
  // 수위 값이 300이상이고 온도가 35도 미만이면 초록 LED ON
  if (waterLevel >= 300 and celsiustemp < 35) {
  	digitalWrite(red_pin, LOW);
    digitalWrite(blue_pin, LOW);
    digitalWrite(green_pin, HIGH);
  }
  // 아니고 만약에 수위 값이 300 미만이면 빨간 LED ON
  else if (waterLevel < 300) {
  	digitalWrite(red_pin, HIGH);
    digitalWrite(blue_pin, LOW);
    digitalWrite(green_pin, LOW);
  }
  // 아니고 만약에 온도가 35도 이상이면 파란 LED ON
  else if (celsiustemp >= 35) {
  	digitalWrite(red_pin, LOW);
    digitalWrite(blue_pin, HIGH);
    digitalWrite(green_pin, LOW);
  }
}