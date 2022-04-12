import sys

N = int(input())
for _ in range(N):
    num, str = input().split()
    a = list(str) # 입력받은 str list화
    text = ''
    # string 초기화

    for i in a:
        text += int(num)*i # text에 string을 합하는 식으로 연결
    print(text)