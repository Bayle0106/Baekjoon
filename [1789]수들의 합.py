import sys

S = int(input())
N = 0
idx = 1

while True:
    if(S-idx<0): break
    if((S-idx)>=0):
        S-=idx
        N+=1
    idx+=1

print(N)