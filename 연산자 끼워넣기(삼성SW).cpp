#include<iostream>
#include<vector>

using namespace std;

// �ʿ��Լ�
// 1. ��Ģ���� �Լ�
// 2. ��� ��츦 ������ �Լ�.
// ��, ��, ��, ���� ����

int num;
int minValue = 1000000000;
int maxValue = -100000000;
int op[4];
int v[12];

void calculate(int result, int cnt) {
	if (cnt == num - 1) {
		if (maxValue < result) maxValue = result;
		if (minValue > result) minValue = result;
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (op[i] > 0) {
			op[i]--;

			switch (i)
			{
			case 0:
				calculate(result + v[cnt + 1], cnt + 1);
				break;
			case 1:
				calculate(result - v[cnt + 1], cnt + 1);
				break;
			case 2:
				calculate(result * v[cnt + 1], cnt + 1);
				break;
			case 3:
				calculate(result / v[cnt + 1], cnt + 1);
				break;
			default:
				break;
			}

			op[i]++;
		}
	}
}

int main() {
	
	cin >> num;
	for (int i = 0; i < num; ++i) cin >> v[i];
	for (int i = 0; i < 4; ++i) cin >> op[i];

	calculate(v[0], 0);

	cout << maxValue << endl << minValue << endl;

	return 0;
}