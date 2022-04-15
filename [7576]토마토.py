import sys
from collections import deque

M, N = map(int, sys.stdin.readline().split())
queue = deque()
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
#4군데의 인접영역에 대한 offset

def bfs():
    num = -1
    while queue:
        num += 1
        for _ in range(len(queue)): # 현재 queue에 저장되있는 자료에 대해 접근
            a, b = queue.popleft()
            for i in range(4):
                x = b + dx[i]
                y = a + dy[i]
                if 0<=x<M and 0<=y<N and matrix[y][x]==0:
                    queue.append([y, x])
                    matrix[y][x] = 1
    for tmp in matrix:
        if 0 in tmp:
            return -1
    return num

matrix = []
for i in range(N):
    matrix.append(list(map(int, sys.stdin.readline().split())))
# matrix에 list의 1차원 배열을 N번 append = column이 N인 2차원 배열

for i in range(N):
    for j in range(M):
        if matrix[i][j] == 1:
            queue.append([i, j]) # 2차원 배열의 queue라고 생각
                                 # 1개[i, j]가 추가될때마다 len은 1임
print(bfs())