#pragma once
#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <iostream>
#include <string>

class Playfair {
    std::string mTable;  // 암호 테이블을 1차원 문자열로 저장
    std::string mPair;   // 동일 문자로 취급할 문자 쌍
    std::string mKey;    // 암호화 키

public:
    Playfair(const std::string& key, const std::string& pair);
    void makeTable();
    void showTable() const;
    std::string makeEncryption(const std::string& text);
};

#endif
