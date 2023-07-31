#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <math.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		int n, k;
		cin >> n >> k;

		vector<int> buildTime(n + 1, 0);
		vector<vector<int>> graph(n + 1, vector<int>());
		vector<int> totalTime(n + 1, 0);
		vector<int> entry(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> buildTime[i];
		}

		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			entry[b]++;
		}

		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (entry[i] == 0)
			{
				q.push(i);
				totalTime[i] = buildTime[i];
			}
		}

		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			
			for(auto g : graph[now])
			{
				totalTime[g] = max(totalTime[g], totalTime[now] + buildTime[g]);
				entry[g]--;
				if (entry[g] == 0)
				{
					q.push(g);
				}
			}
		}

		int w;
		cin >> w;
		cout << totalTime[w] << "\n";
	}

	return 0;
}