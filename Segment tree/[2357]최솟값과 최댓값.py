import sys
MAX = 1000000001

def init_seg(node, start, end):
    if start==end:
        tree[node] = (arr[start], arr[start])
        return tree[node]

    else:
        mid = (start + end)//2
        a = init_seg(node*2, start, mid)
        b = init_seg(node*2+1, mid+1, end)
        tree[node] = (min(a[0], b[0]), max(a[1], b[1]))
        return tree[node]

def find(node, start, end, left, right):
    if left > end or right < start:
        return (1000000001, 0)

    if left <= start and right >= end: # 범위 내부에 존재
        return tree[node]
    
    else : # 범위에 걸쳐서 존재
        mid = (start + end)//2
        a = find(node*2, start, mid, left, right)
        b = find(node*2+1, mid+1, end, left, right)
        return (min(a[0], b[0]), max(a[1], b[1]))

N, M = map(int, sys.stdin.readline().split())
arr = []
tree = [0] * 300000

# input array
for _ in range(N):
    arr.append(int(sys.stdin.readline()))

# init segment tree
init_seg(1, 0, N-1)

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    answer = find(1, 0, N-1, a-1, b-1)
    print('%d %d'%(answer[0], answer[1]))