#include "Playfair.h"
#include <iostream>
using namespace std;

int main() {
    Playfair pfair("test", "a/c"); // 암호화 키, 동일 문자 쌍 설정
    pfair.makeTable();               // 암호화 테이블 생성

    cout << "암호화 테이블 :" << endl;
    pfair.showTable();               // 테이블 출력

    string plaintext = "hello";
    cout << "암호화할 문자열 : " << plaintext << endl;

    string encrypted = pfair.makeEncryption(plaintext); // 암호화 대상
    if (!encrypted.empty()) {
        cout << "암호화 결과 : " << encrypted << endl;
    }
    else {
        cout << "암호화에 실패했습니다." << endl;
    }

    cout << "Enter 버튼을 press";
    cin.get();
    cin.get();
    return 0;
}
