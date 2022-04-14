import sys

def dfs(n):
    stack = [n]
    while stack:
        v = stack.pop()
        visited[v] = True
        for i in graph[v]:
            if not visited[i]:
                stack.append(i)

N, M = map(int, sys.stdin.readline().split())
graph = [[]for _ in range(N+1)]
visited = [False]*(N+1)
num = 0

for _ in range(1, M+1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, N+1):
    if not visited[i]:
        dfs(i)
        num += 1

print(num)