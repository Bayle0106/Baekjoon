#include<iostream>

using namespace std;

int N, K;
int weight[101];
int value[101];
int dp[101][100001];

int max(int a, int b) { if (a < b)return b; return a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> weight[i] >> value[i];
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (j >= weight[i])dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			//현재 i번째의 물건에 대해 추가할지 여부를 판단
			//j가 추가하고자 하는 weight보다 같거나 클 때 이전 정보와 / 이전 - weight[i] + value[i]를 비교
			//이렇게 함으로서 i번째 물건을 추가했을 때 어느 경우가 더 큰지 확인이 가능함.

			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];

	return 0;
}