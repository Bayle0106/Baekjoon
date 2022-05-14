#include<iostream>
#include<stack>

using namespace std;

int dx[] = { -1, 1, 0,0 };
int dy[] = { 0, 0, -1, 1 };

int map[50][50];
int visited[50][50];

int N, M;

void rst(int N, int M) {
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

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

		for (int i = 0; i < 4; ++i)
		{
			int y_ = b + dy[i];
			int x_ = a + dx[i];

			if (check_range(y_, x_))
			{
				if (visited[y_][x_] == 0 && map[y_][x_] == 1)
				{
					visited[y_][x_] = 1;
					s.push(make_pair(y_, x_));
				}
			}
		}
	}
	return;
}

int ans() {
	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				DFS(i, j);
				++answer;
			}
		}
	}
	return answer;
}

int main() {
	int c, num;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		cin >> N >> M >> num;
		rst(N, M);
		for (int j = 0; j < num; ++j)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}
		cout << ans() << endl;
	}
}
