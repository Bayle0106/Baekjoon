import sys

num = int(input())

for _5 in range(num):
    s = input()
    a = list(s)
    sum = 0
    b = 1
    for j in a:
        if j=='O':
            sum+=b
            b+=1
        else:
            b=1
    print(sum)