/*<�ٽ� ����Ʈ>
* max�� min heap 2���� ����
* �̶� max�� ������ min�� �������� ���ų� 1 ���ƾ���
* ���ο� ���� �����µ� ���� ��Ģ�� �����Ҷ� top�� ���� �ݴ� heap���� �ѱ�� push�ϴ� �۾��� �ʿ���
*/

#include<iostream>
#define HALF_MAX 50001

using namespace std;

int Max_heap[HALF_MAX];
int Min_heap[HALF_MAX];
int N, num = 0;
int max_idx = 0, min_idx = 0;

void push_Max(int a) {
	int i = ++max_idx;
	while ((i != 1) && (a > Max_heap[i / 2]))
	{
		Max_heap[i] = Max_heap[i / 2];
		i /= 2;
	}
	Max_heap[i] = a;
}

int Pop_Max() {
	int parent = 1, child = 2;
	int item = Max_heap[parent];
	int temp = Max_heap[max_idx--];

	while (child <= max_idx)
	{
		if ((child < max_idx) && (Max_heap[child] < Max_heap[child + 1])) child++;
		if (temp >= Max_heap[child]) break;
		Max_heap[parent] = Max_heap[child];
		parent = child;
		child *= 2;
	}
	Max_heap[parent] = temp;
	return item;
}

void push_Min(int a) {
	int i = ++min_idx;
	while ((i != 1) && (a < Min_heap[i / 2]))
	{
		Min_heap[i] = Min_heap[i / 2];
		i /= 2;
	}
	Min_heap[i] = a;
}

int Pop_Min() {
	int parent = 1, child = 2;
	int item = Min_heap[parent];
	int temp = Min_heap[min_idx--];

	while (child <= min_idx)
	{
		if ((child < min_idx) && (Min_heap[child] > Min_heap[child + 1])) child++;
		if (temp <= Min_heap[child])break;
		Min_heap[parent] = Min_heap[child];
		parent = child;
		child *= 2;
	}
	Min_heap[parent] = temp;
	return item;
}

void push(int a) {
	num++;
	if (num % 2 == 1) {
		if ((a > Min_heap[1]) && (num != 1))
		{
			int temp = Pop_Min();
			push_Max(temp);
			push_Min(a);
		}
		else push_Max(a);
	}

	else
	{
		if (a < Max_heap[1])
		{
			int temp = Pop_Max();
			push_Min(temp);
			push_Max(a);
		}
		else push_Min(a);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		push(temp);
		cout << Max_heap[1] << '\n';
	
	}
	return 0;
}