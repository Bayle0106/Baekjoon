import sys
from collections import deque

# recursive dfs
"""
def dfs(n):
    print(n, end=' ')
    visited[n] = True
    for i in graph[n]:
        if not visited[i]:
            dfs(i)

"""

# iterative dfs
def dfs(n):
    stack = [n]
    while stack:
        v = stack.pop()
        if not visited[v]:
            print(v, end=' ')
            visited[v]=True
        for i in reversed(graph[v]):
            if not visited[i]:
                stack.append(i)

def bfs(n):
    visited[n]=True
    queue = deque([n])
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True


n, num, start = map(int, input().split())
visited = [False] * (n+1)
graph = [[] for _ in range(n+1)]

for _ in range(num):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n+1):
    graph[i].sort()

dfs(start)
print()
visited = [False] * (n+1)
bfs(start)