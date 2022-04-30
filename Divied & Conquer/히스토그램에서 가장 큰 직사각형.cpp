#include<iostream>

using namespace std;
long long arr[100001];

// 문제에서는 높이가 최대 10억, 너비가 10만이기 때문에 int 자료형에 담을 수 없다.
long long solve(int left, int right) {
	// 기저 조건
	if (left == right) return arr[left];
	long long mid = (left + right) / 2;
	
	// 분할
	long long ret = max(solve(left, mid), solve(mid + 1, right));

	long long lo = mid, hi = mid + 1;
	long long height = min(arr[lo], arr[hi]);
	ret = max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1]))
		{
			++hi;
			height = min(height, arr[hi]);
		}
		else
		{
			--lo;
			height = min(height, arr[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)break;
		else
		{
			for (int i = 0; i < n; ++i)
				cin >> arr[i];	
		}
		cout << solve(0, n - 1) << endl;
	}
}