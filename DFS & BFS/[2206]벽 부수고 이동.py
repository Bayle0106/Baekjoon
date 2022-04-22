import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
matrix = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs():
    visited = [[[0] * 2 for i in range(M)] for i in range(N)]
    visited[0][0][0]=1
    # N x M x 2의 3차원 array
    
    queue = deque()
    queue.append([0, 0, 0])
    # queue의 마지막 성분 1: 1번 뚫음 / 0: 한번도 뚫지 않음

    while queue:
        a, b, c = queue.popleft()

        if a==N-1 and b==M-1:
            return visited[a][b][c]

        for i in range(4):
            y = a + dy[i]
            x = b + dx[i]
            if 0<=y<N and 0<=x<M:
                if matrix[y][x]==1 and c==0: # 벽 만남 + 벽뚫 0
                    visited[y][x][1] = visited[a][b][0]+1
                    queue.append([y, x, 1])
                elif matrix[y][x]==0 and visited[y][x][c]==0: # 벽 X + 미방문
                    visited[y][x][c] = visited[a][b][c]+1
                    queue.append([y, x, c])
                # 사실상 경우는 2가지밖에 존재하지 않음 이부분에 주의
    return -1

for i in range(N):
    matrix.append(list(map(int, input())))

print(bfs())