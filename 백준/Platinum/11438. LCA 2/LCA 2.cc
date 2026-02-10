#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NODE 100'001
#define LOG 18

int N, M;
int parent[MAX_NODE][LOG] = { 0, };
int depth[MAX_NODE] = { 0, };

std::vector<int> graph[MAX_NODE];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	depth[1] = 1;
	parent[1][0] = 0;
	std::queue<int> q;
	q.push(1);
	while (false == q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto& next : graph[curr])
		{
			if (0 == depth[next])
			{
				depth[next] = depth[curr] + 1;
				parent[next][0] = curr;
				q.push(next);
			}
		}
	}

	for (int i = 1; i < LOG; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;

		if (depth[a] < depth[b])
		{
			std::swap(a, b);
		}

		for (int k = LOG - 1; k >= 0; k--)
		{
			if (depth[a] - (1 << k) >= depth[b])
			{
				a = parent[a][k];
			}
		}

		if (a == b)
		{
			std::cout << a << '\n';
			continue;
		}

		for (int k = LOG - 1; k >= 0; k--)
		{
			if (parent[a][k] != parent[b][k])
			{
				a = parent[a][k];
				b = parent[b][k];
			}
		}

		std::cout << parent[a][0] << '\n';
	}

	return 0;
}