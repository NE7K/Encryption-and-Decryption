import copy

read_file = 'C:/Users/원문.txt'
kfile = 'C:/Users/원문_키값.txt’
# 인코딩 오류가 존재하지 않지만, 존재한다면 아래와 같이 인코딩 설정 <위 경로는 자유롭게 수정>

with open(read_file, 'r', encoding='cp949') as file: # 인코딩 오류로 cp949 설정
    text_content = file.read()

Al_num = [0] * 26

for char in text_content:
    if char.isalpha():
        Al_num[ord(char.lower()) - 97] += 1

with open(kfile, 'w', encoding='utf-8') as key_file:
    key_file.writelines([f"{chr(97 + i)}={Al_num[i]}\n" for i in range(26)])
