#include<iostream>
#include<math.h>

using namespace std;

int num;
int score[21][21];
bool check[21] = { false };
int ans = 987654321;

void dfs(int cnt, int idx) {
	if (cnt == num / 2) {
		// ºñ±³
		int linkScore = 0, startScore = 0;

		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				if (check[i] && check[j]) startScore += score[i][j];
				if (!check[i] && !check[j]) linkScore += score[i][j];
			}
		}
		int tmp = abs(startScore - linkScore);
		ans = min(ans, tmp);
		return;
	}

	for (int i = idx; i < num; ++i) {
		check[i] = true;
		dfs(cnt + 1, i + 1);
		check[i] = false;
	}
}

int main() {
	cin >> num;
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			cin >> score[i][j];
		}
	}

	dfs(0, 1);

	cout << ans << endl;
	return 0;
}