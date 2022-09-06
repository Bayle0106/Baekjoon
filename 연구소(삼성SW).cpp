#include<iostream>
#include<queue>

#define maxH 8
#define maxW 8

using namespace std;

int height, width;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int currentMap[maxH][maxW];
int inputMap[maxH][maxW];
int ans = 0; // 안전영역의 크기

// 현재의 map을 tmp에 복사하는 과정
void copyMap(int current[maxH][maxW], int tmp[maxH][maxW]) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tmp[i][j] = current[i][j];
		}
	}
}

// bfs를 이용하여 2의 개수를 구하는 함수
// 단, 여기서 currentMap을 직접 건드리면 안됨 -> 2가 퍼져있는 상태로 바뀌므로 이후 bfs에 영향이 생김.
void bfs() {
	int tmp[maxH][maxW];
	copyMap(currentMap, tmp);

	// 바이러스가 있는 부분의 위치를 얻어오기
	queue<pair<int, int>> q;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (tmp[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
			if (tmp[ny][nx] == 0) {
				tmp[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (tmp[i][j] == 0)cnt++;
		}
	}

	ans = max(ans, cnt);
}

// 벽3개를 설치하는 함수.
void wall(int cnt) {
	// 벽 3개 = 설치 완료된 경우, bfs호출
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {

			// 벽이 아닌 경우.
			if (currentMap[i][j] == 0) {
				currentMap[i][j] = 1;
				wall(cnt + 1);
				currentMap[i][j] = 0;
			}
		}
	}
}

// 메인 함수
int main() {
	cin >> height >> width;

	// currnetMap 초기화.
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			cin >> inputMap[i][j];
		}
	}

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (inputMap[i][j] == 0) {
				copyMap(inputMap, currentMap);
				currentMap[i][j] = 1;
				wall(1);
				currentMap[i][j] = 0;
			}
		}
	}

	cout << ans;
}