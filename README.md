# 플레이페어 암호화 및 복호화 - C++

 위 프로그램은 main.cpp, Playfair.h, Playfair.cpp로 구성됩니다.

 main.cpp는 사용자가 설정한 키와 문자 쌍을 기반으로 Playfair 객체를 생성하고, 암호화 테이블을 만든 뒤 입력 문자열을 암호화하여 결과를 출력하는 역할을 합니다.

Playfair.h는 Playfair 클래스의 선언을 포함하고 있습니다. 키와 문자 쌍 그리고 암호화 테이블을 관리하는 변수를 정의해놓았으며, 생성 및 출력을 담고 있습니다.

Playfair.cpp는 테이블 생성은 입력된 키와 문자 쌍을 기반으로 중복 제거와 알파벳 보충을 통해 이루어지며, 암호화는 규칙에 따라 입력 문자열을 변환합니다.

> 참고사항
> makeTable()은 키와 문자 쌍을 기반으로 중복 제거 후 알파벳 추가해 테이블 생성
> makeEncryption()은 암호화된 문자 반환

## 실행 화면 및 결과

![Image](https://github.com/user-attachments/assets/a5b7f815-8651-40e6-bbca-5bf6d7f7a0b7)

키 : test
쌍 : a/c
암호화하려는 문장 및 단어 : hello


# 플레이페어 암호화 및 복호화 - Python

## 1. 원문을 통해서 키 값을 생성하고 개수를 파악하는 소스

‘암호문’과 ‘키 값’ 파일을 생성하는데 꼭 필요한 기본적인 재료인 원문 내용을 바탕으로 알파벳별로 문자를 읽어와 각 문자의 개수를 파악하고 원문_키값.txt에 저장되도록 코딩했습니다.

등장 횟수를 계산 후 정렬하여 사용했지만, 직접 리스트에서 최소값을 반복 탐색하는 방식으로 코딩할 수도 있습니다.

![Image](https://github.com/user-attachments/assets/afea4e3d-0a08-47ab-978a-cca0a00ca567)

## 2. 원문 키 값을 읽어와 오름차순으로 정렬 후 암호문으로 변경하는 소스

정렬된 알파벳을 매핑해 암호화했지만, 원문을 키 값과 대조해 알파벳을 변환할 수 있습니다.

![Image](https://github.com/user-attachments/assets/aa8a4dfa-9a93-4800-989f-174e09c3a10b)

## 3. 암호문 키 값을 읽어와서 다시 원문을 복원 시키는 소스

복호화 방식은 딕셔너리 기반으로 복호화할 수도 있지만, 리스트 탐색을 통해서 알파벳을 복원할 수도 있습니다.

![Image](https://github.com/user-attachments/assets/b41e320f-8544-4a2d-bc44-b0697c1f23f0)
