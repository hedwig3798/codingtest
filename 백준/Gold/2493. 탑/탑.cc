#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> result(n, 0);
	stack<pair<int, int>> s;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		s.push({i, input});
	}

	stack<pair<int, int>> r;
	while (!s.empty())
	{
		pair<int, int> now = s.top();
		s.pop();
		
		if (r.empty() || now.second < r.top().second)
		{
			r.push(now);
			continue;
		}

		while (!r.empty())
		{
			result[r.top().first] = now.first + 1;
			r.pop();

			if (r.empty() || now.second < r.top().second)
			{
				r.push(now);
				break;
			}
		}
	}

	for(auto c : result) 
	{
		cout << c << ' ';
	}

	return 0;
}