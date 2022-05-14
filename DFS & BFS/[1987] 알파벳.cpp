// 알파벳의 visited의 문제이므로 알파벳 개수에 대한 배열만 있어도 됨.
// 별도의 메모리 카피 없이 함수 호출 시점에 visited만 일치하면 됨.

#include<iostream>
#include<vector>

using namespace std;

vector<string> map;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int visited[26] = { 0 };

int R, C;
int m = 1;

void DFS(int y, int x, int path) {
	m = max(path, m);

	for (int i = 0; i < 4; ++i)
	{
		int y_ = y + dy[i];
		int x_ = x + dx[i];

		if (0 <= y_ && y_ < R && 0 <= x_ && x_ < C)
		{
			// 미방문
			if (visited[map[y_][x_] - 'A'] == 0)
			{
				visited[map[y_][x_] - 'A'] = 1;
				DFS(y_, x_, path + 1);
				visited[map[y_][x_] - 'A'] = 0;
			}
		}
	}
}

int main() {
	int answer = 0;

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		string tmp;
		cin >> tmp;
		map.push_back(tmp);
	}

	visited[map[0][0] - 'A'] = 1;
	DFS(0,0,m);

	answer = m;
	cout << answer << endl;
	return 0;
}