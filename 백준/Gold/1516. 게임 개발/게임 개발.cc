#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 501

int N;
int constructTime[MAX_COUNT];
int indegree[MAX_COUNT] = { 0, };
int ans[MAX_COUNT] = { 0, };

std::vector<int> preced[MAX_COUNT];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	std::queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		int a;
		std::cin >> a;
		constructTime[i] = a;

		while (true)
		{
			int b;
			std::cin >> b;
			if (-1 == b)
			{
				break;
			}
			preced[b].push_back(i);
			indegree[i]++;
		}

		if (0 == indegree[i])
		{
			q.push(i);
			ans[i] = constructTime[i];
		}
	}

	while (false == q.empty())
	{
		int cNode = q.front();
		q.pop();

		for (auto& nNode : preced[cNode])
		{
			--indegree[nNode];
			ans[nNode] = std::max(ans[nNode], constructTime[nNode] + ans[cNode]);
			if (0 == indegree[nNode])
			{
				q.push(nNode);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		std::cout << ans[i] << '\n';
	}


	return 0;
}