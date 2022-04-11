import sys

H, M, S = map(int, input().split())
total = H*3600 + M*60 + S
t = int(input())

total += t
S = (total%60)
total -= S

M = (total%3600)/60
total -=M*60

H=(total/3600)%24

print('%d %d %d' %(H,M,S))