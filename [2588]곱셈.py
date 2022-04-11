import sys

#A, B = map(int, input().split())
A = int(input())
B = int(input())
tmp = B

for i in range(3):
    print(A*(tmp%10))
    tmp=int(tmp/10)

print(A*B)
    