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
int ans = 0; // ���������� ũ��

// ������ map�� tmp�� �����ϴ� ����
void copyMap(int current[maxH][maxW], int tmp[maxH][maxW]) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tmp[i][j] = current[i][j];
		}
	}
}

// bfs�� �̿��Ͽ� 2�� ������ ���ϴ� �Լ�
// ��, ���⼭ currentMap�� ���� �ǵ帮�� �ȵ� -> 2�� �����ִ� ���·� �ٲ�Ƿ� ���� bfs�� ������ ����.
void bfs() {
	int tmp[maxH][maxW];
	copyMap(currentMap, tmp);

	// ���̷����� �ִ� �κ��� ��ġ�� ������
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

// ��3���� ��ġ�ϴ� �Լ�.
void wall(int cnt) {
	// �� 3�� = ��ġ �Ϸ�� ���, bfsȣ��
	if (cnt == 3) {
		bfs();
		return;
	}

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {

			// ���� �ƴ� ���.
			if (currentMap[i][j] == 0) {
				currentMap[i][j] = 1;
				wall(cnt + 1);
				currentMap[i][j] = 0;
			}
		}
	}
}

// ���� �Լ�
int main() {
	cin >> height >> width;

	// currnetMap �ʱ�ȭ.
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