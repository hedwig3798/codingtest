#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#define INF 1e9
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> inCount(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		inCount[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	vector<int> result;

	for (int i = 1; i < inCount.size(); i++)
	{
		if (inCount[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.top();
		q.pop();
		result.push_back(now);

		for(auto& next : graph[now])
		{
			inCount[next]--;
			if (inCount[next] == 0)
			{
				q.push(next);
				continue;
			}
		}
	}

	for(auto& r : result) 
	{
		cout << r << " ";
	}

	return 0;
}