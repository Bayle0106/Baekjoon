import sys
from collections import deque

def binary_bfs(n, check):
    k=0
    queue = deque([])
    queue.append([n, k])
    while queue:
        v, k = queue.popleft()
        check[v]=True
        visited[v][k]=1
        k = 1-k
        for i in graph[v]:
            if visited[i][k] == 0:
                if visited[i][1-k]==1:
                    return False
                visited[i][k]=1
                queue.append([i, k])
    return True

case = int(sys.stdin.readline())

for _ in range(case):
    V, E = map(int, sys.stdin.readline().split())
    visited = [[0]*2 for _ in range(V+1)]
    graph = [[]for _ in range(V+1)]
    check = [False]*(V+1)
    for _ in range(E):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)
    
    binary = 0
    for i in range(1, V+1):
        if not check[i]:
            if binary_bfs(i, check)==False:
                binary = 1
                break
    if binary == 1: print('NO')
    else: print('YES')