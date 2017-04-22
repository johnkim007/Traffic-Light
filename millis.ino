/*
   millis
   
   이 스케치는 millis() 함수를 시험하기 위한 예제입니다.

   스케치 setup() 함수에 for 반복문을 활용하여 millis()
   함수와 delay(...) 함수를 사용하여 ms(밀리세컨) 단위로
   스케치가 시작하여 흐른 시간을 COUNT 갯수만큼 측정하여
   시리얼 모니터로 출력합니다.
   
   http://blog.naver.com/msyang59/220846396916 
   
   이 예제 코드는 공유 저작물입니다.
   
 */
#define COUNT 16
#define DELAY 10

long unsigned times[COUNT];
char buf[32];

void setup() {
  // 여기에 초기화 부분을 넣어 주세요. 이것은 한번만 실행됩니다:
  // 시리얼 통신 속도를 설정합니다:
  Serial.begin(9600);

  // 안내 글을 출력합니다:
  Serial.println("millis 예제");
  Serial.println("-----------");
  
  times[0] = 0;
  // COUNT 갯수 만큼 us 시간을 반복하여 읽습니다:
  for(int i = 1; i < COUNT; i++) {
    times[i] = millis();
    delay(DELAY);    
  }
  
  // 읽어 놓은 ms 시간을 시리얼 모니터로 출력합니다:
  for(int i = 1; i < COUNT; i++) {
    sprintf(buf, "측정[%2i]: %6lums Δ%lums", i, times[i], times[i] - times[i - 1]);
    Serial.println(buf);
  }
}

void loop() {
  // 여기에 주 처리 부분을 넣어 주세요. 이것은 반복 실행됩니다:
}
[출처] 시간 함수들: millis|작성자 과객
