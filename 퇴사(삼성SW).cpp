#include<iostream>
#include<vector>

using namespace std;

int num;
vector<pair<int, int>> plan;
int ans = 0;

void dfs(int cost, int day) {
	// 퇴사일의 경우
	if (day == num) {
		ans = max(ans, cost);
		return;
	}

	int tmp = day + plan[day].first;

	if (tmp <= num) {
		dfs(cost + plan[day].second, tmp);
	}

	dfs(cost, day + 1);
}

int main() {
	int day;
	int cost;

	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> day >> cost;
		plan.push_back({ day,cost });
	}

	dfs(0, 0);

	cout << ans;
	return 0;
}