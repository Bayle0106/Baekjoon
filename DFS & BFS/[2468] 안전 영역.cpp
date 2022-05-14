#include<iostream>
#include<queue>

using namespace std;

bool visited[101][101];
int map[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N;

void BFS(int y, int x, int height) {
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int b = cur.first + dy[i];
			int a = cur.second + dx[i];

			if (0 <= b && b < N && 0 <= a && a < N && !visited[b][a] && map[b][a] > height)
			{
				q.push(make_pair(b, a));
				visited[b][a] = true;
			}
		}
	}
	return;
}

int check(int height) {
	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] > height && !visited[i][j])
			{
				++answer;
				BFS(i, j, height);
			}
		}
	}
	return answer;
}

int main() {
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				visited[j][k] = false;
		int result = check(i);

		if (result == 0) break;
		if (result >= answer) answer = result;
	}

	cout << answer;
	return 0;
}