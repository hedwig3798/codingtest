#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_NUM 100'001

int V, E;
std::vector<int> graphs[MAX_NUM];
int isVisit[MAX_NUM] = { 0, };
std::vector<std::pair<int, int>> ans;

int DFS(int _curr, int _parent)
{
	static int num = 1;

	int result = num;
	isVisit[_curr] = num;
	num++;

	for (auto& next : graphs[_curr])
	{
		if (_parent == next)
		{
			continue;
		}
		if (isVisit[next] == 0)
		{
			int order = DFS(next, _curr);
			result = std::min(result, order);

			if (order > isVisit[_curr])
			{
				ans.push_back({ std::min(_curr, next), std::max(_curr, next) });
			}
		}
		else
		{
			result = std::min(result, isVisit[next]);
		}
	}

	return result;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b;
		std::cin >> a >> b;
		graphs[a].push_back(b);
		graphs[b].push_back(a);
	}

	DFS(1, 0);

	std::cout << ans.size() << '\n';

	std::sort(ans.begin(), ans.end());

	for (auto& itr : ans)
	{
		std::cout << itr.first << ' ' << itr.second << '\n';
	}

	return 0;
}