#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int result = 0;
	vector<int> data;
	data.push_back(0);
	stack <int> s;
	s.push(0);

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		data.push_back(num);
	}

	data.push_back(0);

	for (int i = 1; i <= N + 1; i++)
	{
		while (!s.empty() && data[s.top()] > data[i])
		{
			int check = s.top();
			s.pop();
			result = max(result, data[check] * (i - s.top() - 1));
		}
		s.push(i);
	}

	cout << result;
}