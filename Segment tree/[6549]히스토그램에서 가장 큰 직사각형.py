import sys

def init_seg(node, start, end):
    if start == end:
        tree[node] = arr[start]
        return tree[node]

    mid = (start + end)//2
    tree[node] = min(init_seg(node*2, start, mid), init_seg(node*2+1, mid+1, end))
    return tree[node]
    

def find(node, start, end):
    b=1

arr = []
tree = [0]*300000

while True:
    arr = list(map(int, sys.stdin.readline().split()))
    a = arr.pop(0)

    if a==1:
        break

    init_seg(1, 0, a-1)


    
    