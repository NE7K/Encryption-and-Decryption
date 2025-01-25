#include "Playfair.h"
#include <algorithm>
#include <vector>

using namespace std;

Playfair::Playfair(const string& key, const string& pair)
    : mKey(key), mPair(pair), mTable(25, '\0') {}

void Playfair::makeTable() {
    string key = mKey;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // 동일 문자로 취급할 쌍 중 하나 제거
    alphabet.erase(remove(alphabet.begin(), alphabet.end(), mPair[2]), alphabet.end());

    // 키에서 중복 제거
    string uniqueKey;
    for (char c : key) {
        if (uniqueKey.find(c) == string::npos && isalpha(c)) {
            if (c == mPair[2]) {
                c = mPair[0];
            }
            if (uniqueKey.find(c) == string::npos) {
                uniqueKey += c;
            }
        }
    }

    // 입력 문자열 생성 (키의 문자 + 알파벳)
    string tableInput = uniqueKey;
    for (char c : alphabet) {
        if (tableInput.find(c) == string::npos) {
            tableInput += c;
        }
    }

    // 테이블 문자 할당 (중복이 없는지 확인)
    for (int i = 0; i < 25; ++i) {
        mTable[i] = tableInput[i];
    }
}

void Playfair::showTable() const {
    for (int i = 0; i < 25; ++i) {
        cout << mTable[i] << " ";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
}

string Playfair::makeEncryption(const string& text) {
    // 입력 텍스트 정제
    string sanitizedText = text;
    sanitizedText.erase(remove_if(sanitizedText.begin(), sanitizedText.end(), [](char c) { return !isalpha(c); }), sanitizedText.end());
    transform(sanitizedText.begin(), sanitizedText.end(), sanitizedText.begin(), ::tolower);

    replace(sanitizedText.begin(), sanitizedText.end(), mPair[2], mPair[0]);

    // 짝수 길이로 맞추기
    for (size_t i = 0; i < sanitizedText.length(); i += 2) {
        if (i + 1 == sanitizedText.length() || sanitizedText[i] == sanitizedText[i + 1]) {
            sanitizedText.insert(i + 1, "x");
        }
    }

    string result;

    // 두 글자씩 암호화
    for (size_t i = 0; i < sanitizedText.length(); i += 2) {
        char a = sanitizedText[i];
        char b = sanitizedText[i + 1];

        // 테이블에서 두 문자의 인덱스를 찾기
        auto aIt = find(mTable.begin(), mTable.end(), a);
        auto bIt = find(mTable.begin(), mTable.end(), b);

        if (aIt == mTable.end() || bIt == mTable.end()) {
            cerr << "Error" << endl;
            return "";
        }

        int aIndex = distance(mTable.begin(), aIt);
        int bIndex = distance(mTable.begin(), bIt);

        int aRow = aIndex / 5, aCol = aIndex % 5;
        int bRow = bIndex / 5, bCol = bIndex % 5;

        if (aRow == bRow) { // 같은 행에 있는 경우
            // 오른쪽 문자, 마지막 열의 경우 첫 번째 열로 돌아옴
            result += mTable[aRow * 5 + (aCol + 1) % 5];
            result += mTable[bRow * 5 + (bCol + 1) % 5];
        }
        else if (aCol == bCol) { // 같은 열에 있는 경우
            // 아래쪽 문자, 마지막 행의 경우 첫 번째 행으로 돌아옴
            result += mTable[((aRow + 1) % 5) * 5 + aCol];
            result += mTable[((bRow + 1) % 5) * 5 + bCol];
        }
        else { // 다른 행과 열에 있는 경우 (직사각형 규칙 적용)
            // 각각의 행과 열이 만나는 교차 위치의 문자
            result += mTable[aRow * 5 + bCol];
            result += mTable[bRow * 5 + aCol];
        }
    }

    return result;
}


