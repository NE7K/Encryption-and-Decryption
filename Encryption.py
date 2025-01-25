kfile = 'C:/Users/원문_키값.txt'
c_file = 'C:/Users/암호문.txt'
ck_file = 'C:/Users/암호문_키값.txt'
# 인코딩 오류가 존재하지 않지만, 존재한다면 아래와 같이 인코딩 설정

with open(kfile, 'r', encoding='utf-8') as key_file:
    alphabet_counter = {line.split('=')[0]: int(line.split('=')[1]) for line in key_file}

sorted_alphabets = sorted(alphabet_counter.items(), key=lambda x: x[1]) # 크기가 작은 순서부터 즉, 오름차순으로 나열
sorted_alphabets_only = [item[0] for item in sorted_alphabets]

original_alphabets = [chr(i) for i in range(97, 123)]  # a부터 z까지 범위 설정

encryption_map = {original_alphabets[i]: sorted_alphabets_only[i] for i in range(26)}

with open(ck_file, 'w', encoding='utf-8') as cipher_key_file:
    cipher_key_file.writelines([
        f"{original_alphabets[i]}({alphabet_counter[original_alphabets[i]]}) -> {sorted_alphabets_only[i]}({alphabet_counter[sorted_alphabets_only[i]]})\n" 
        for i in range(26)
    ])

cipher_text = [
    encryption_map[char.lower()].upper() if char.isupper() else encryption_map[char.lower()] if char.isalpha() else char
    for char in text_content
]

with open(c_file, 'w', encoding='utf-8') as cipher_file: # 인코딩 오류로 설정
    cipher_file.write(''.join(cipher_text))
