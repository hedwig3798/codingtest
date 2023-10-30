#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>());
	vector<int> inputCount(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int count;
		cin >> count;

		vector<int> singer(count);
		for (int j = 0; j < count; j++)
		{
			cin >> singer[j];
		}

		for (int j = 0; j < count - 1; j++)
		{
			graph[singer[j]].push_back(singer[j + 1]);
			inputCount[singer[j + 1]]++;
		}
	}

	queue<int> q;

	for (int i = 1; i < inputCount.size(); i++)
	{
		if (inputCount[i] == 0)
		{
			q.push(i);
		}
	}

	vector<int> ans;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		ans.push_back(now);

		for(auto& g : graph[now])
		{
			inputCount[g]--;
			if (inputCount[g] == 0)
			{
				q.push(g);
			}
		}
	}

	if (ans.size() != N) 
	{
		cout << 0;
	}
	else
	{
		for(auto& a : ans) 
		{
			cout << a << "\n";
		}
	}

	return 0;
}