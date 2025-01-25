c_file = 'C:/Users/암호문.txt'
ck_file = 'C:/Users/암호문_키값.txt'
rc_file = 'C:/Users/복원된_원문.txt'
# 인코딩 오류가 존재하지 않지만, 존재한다면 아래와 같이 인코딩 설정

with open(c_file, 'r', encoding='utf-8') as file:
    cipher_text = file.read()

with open(ck_file, 'r', encoding='utf-8') as cipher_key_file:
    decryption_map = {
        line.split(' -> ')[1].split('(')[0]: line.split(' -> ')[0].split('(')[0]
        for line in cipher_key_file if '->' in line
    }

decrypted_text = [
    decryption_map[char.lower()].upper() if char.isupper() else decryption_map[char.lower()] if char.isalpha() else char
    for char in cipher_text
]

with open(rc_file, 'w', encoding='utf-8') as decrypted_file:
    decrypted_file.write(''.join(decrypted_text))
