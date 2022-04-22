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

    # index가 범위 밖에 존재 -> 무시
    if index < start or index > end:
        return

    # update node
    tree[node] += change

    # index도착 이전 -> leaf node update
    if start < end:
        mid = (start + end)//2
        update(node*2, start, mid, index, change)
        update(node*2+1, mid+1, end, index, change)

def sum(node, start, end, left, right):

    # left ~ right가 범위 밖에 있는 경우 -> 무시
    if right < start or left > end:
        return 0

    # left ~ right 안쪽에 있는 경우 -> 그냥 node값 반환
    if left <= start and end <= right:
        return tree[node]

    # 그외: leaf node 합
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