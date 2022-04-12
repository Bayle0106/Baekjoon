import sys
y = int(input())

a = 0
if y % 400 ==0:
    a = 1
elif y % 4 == 0:
    if y % 100 == 0:
        a = 0
    else: a = 1
print(a)