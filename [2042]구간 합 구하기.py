import sys

def init(node, start, end):
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    
    else:
        mid = (start + end)//2
        tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end)
        return tree[node]

def update(node, start, end, index, change):
    if index < start or index > end:
        return
    # update node
    tree[node] += change

    if start < end:
        mid = (start + end)//2
        update(node*2, start, mid, index, change)
        update(node*2+1, mid+1, end, index, change)

def sum(node, start, end, left, right):
    if right < start or left > end:
        return 0

    if left <= start and end <= right:
        return tree[node]

    mid = (start + end)//2
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right)

N, M, K = map(int, sys.stdin.readline().split())
arr = []
tree = [0] * 3000000

# input arr
for _ in range(N):
    arr.append(int(sys.stdin.readline()))

# init segment tree
init(1, 0, N-1)

# update & sum
for _ in range(M+K):
    a, b, c = map(int, sys.stdin.readline().split())
    
    # update segment tree
    if a==1:
        change = c - arr[b-1]
        update(1, 0, N-1, b-1, change)

    # sum node between b-1 ~ c-1
    elif a==2:
        print(sum(1, 0, N-1, b-1, c-1))