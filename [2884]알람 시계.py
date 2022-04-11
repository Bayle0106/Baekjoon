import sys

H, M = map(int, input().split())

if((M-45)<0):
    M+=15
    if((H-1)<0): H+=23
    else: H-=1
else: M-=45

print('%d %d'%(H, M))
