import sys

H, M = map(int, input().split())
t = int(input())

M += t
if M>=60:
    a=int(M/60)
    H+=a
    M-=a*60
    if H>=24:
        b=int(H/24)
        H-=24*b

print('%d %d'%(H, M))