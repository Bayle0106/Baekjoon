#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		list<char> l;
		list <char>::iterator it = l.begin();

		for (char tmp : str)
		{
			switch (tmp)
			{
			case '<':
				if (it != l.begin()) --it;
				break;

			case '>':
				if (it != l.end()) ++it;
				break;

			case '-':
				if (!l.empty() && it != l.begin())
				{
					--it;
					l.erase(it);
				}
				break;

			default:
				// 현재 가리키는 iterator의 위치에 삽입 -> 만약 it가 end면 같이 이동하는 느낌
				// -> 엄밀히는 end() 컨테이너를 가리키는 것이므로
				l.insert(it, tmp);
				break;
			}
		}

		for (char tmp : l)
			cout << tmp;
		l.clear();
		cout << "\n";
	}
}

