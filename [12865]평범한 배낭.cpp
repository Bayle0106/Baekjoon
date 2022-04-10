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
			//���� i��°�� ���ǿ� ���� �߰����� ���θ� �Ǵ�
			//j�� �߰��ϰ��� �ϴ� weight���� ���ų� Ŭ �� ���� ������ / ���� - weight[i] + value[i]�� ��
			//�̷��� �����μ� i��° ������ �߰����� �� ��� ��찡 �� ū�� Ȯ���� ������.

			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];

	return 0;
}