#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;

int V, E, P;
vector<vector<pii>> graph;

int Dik(int _start, int _end)
{
	priority_queue<pii> pq;
	vector<int> totalCost(V + 1, le9);

	pq.push({ 0, _start });

	while (!pq.empty())
	{
		pii node = pq.top();
		pq.pop();

		int curr = node.second;
		int currCost = -node.first;

		for (auto& g : graph[curr])
		{
			int next = g.second;
			int nextCost = g.first + currCost;

			if (nextCost < totalCost[next])
			{
				totalCost[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}

	return totalCost[_end];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V >> E >> P;

	if (P == 1)
	{
		cout << "SAVE HIM";
		return 0;
	}

	graph.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	int masan = Dik(1, V);
	int gun = Dik(1, P) + Dik(P, V);

	if (masan == gun)
	{
		cout << "SAVE HIM";
	}
	else
	{
		cout << "GOOD BYE";
	}

	return 0;
}