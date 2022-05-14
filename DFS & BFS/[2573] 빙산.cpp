#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int dx[] = { -1, 1, 0,0 };
int dy[] = { 0, 0, -1, 1 };

int map[300][300];
int visited[300][300];

int N, M;
int nonzero = 0;

bool check_range(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < M) return true;
	else return false;
}

void DFS(int y, int x) {
	stack<pair<int, int>> s;
	s.push(make_pair(y, x));
	visited[y][x] = 1;

	while (!s.empty())
	{
		auto cur = s.top();
		int b = cur.first;
		int a = cur.second;
		s.pop();

		int cnt = 0;
		for (int i = 0; i < 4; ++i)
		{
			int y_ = b + dy[i];
			int x_ = a + dx[i];

			if (check_range(y_, x_))
			{
				// 인접한 0인 부분 + 미방문: 이전 loop에서 0이 된 경우 기존의 0이 아니므로 배제
				if (map[y_][x_] == 0 && visited[y_][x_] == 0) ++cnt;

				else if(map[y_][x_] > 0 && visited[y_][x_] == 0)
				{
					visited[y_][x_] = 1;
					s.push(make_pair(y_, x_));
				}
			}
		}

		// map의 값이 음수가 되는 경우
		if ((map[b][a] - cnt) <= 0)
		{
			map[b][a] = 0;
			--nonzero;
		}
		else map[b][a] -= cnt;
	}
}

int main() {
	int year = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int t;
			cin >> t;
			if (t > 0)++nonzero;
			map[i][j] = t;
		}
	}
		
	// 모든 node가 0이되거나 또는 area가 2이상이 될때까지
	bool tmp = false;
	while (nonzero > 0)
	{
		// 변수 초기화
		int area = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				visited[i][j] = 0;

		// DFS탐색
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (map[i][j] > 0 && visited[i][j] == 0)
				{
					DFS(i, j);
					++area;
				}
			}
		}

		// area가 2이상인 경우 break
		if (area >= 2)
		{
			tmp = true;
			break;
		}
		++year;
	}

	if (!tmp) year = 0;
	cout << year;
}
