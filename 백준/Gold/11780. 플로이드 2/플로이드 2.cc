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
#define MOD 1'000'000'000;
typedef long long ll;

using namespace std;

int n, m;

vector<vector<int>> busMap;

vector<vector<int>> costs;
vector<vector<int>> vNodes;

vector<int> route;

void PrintRoute(int _start, int _end)
{
	if (vNodes[_start][_end] == 0)
	{
		route.push_back(_start);
		route.push_back(_end);
		return;
	}

	PrintRoute(_start, vNodes[_start][_end]);
	route.pop_back();
	PrintRoute(vNodes[_start][_end], _end);


}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	busMap = vector<vector<int>>(n + 1, vector<int>(n + 1));
	vNodes = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	costs = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;

		costs[s][e] = min(costs[s][e], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (costs[i][j] > costs[i][k] + costs[k][j])
				{
					costs[i][j] = costs[i][k] + costs[k][j];
					vNodes[i][j] = k;
				}

			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (costs[i][j] >= INF)
			{
				cout << 0 << ' ';
				continue;
			}
			cout << costs[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (costs[i][j] >= INF)
			{
				cout << 0 << '\n';
				continue;
			}
			route.clear();
			PrintRoute(i, j);

			cout << route.size() << ' ';
			for (auto& n : route)
			{
				cout << n << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}