#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 50'001
#define LOG 17

int N, M;
std::vector<int> tree[MAX_COUNT];

int level[MAX_COUNT] = { 0, };
int parent[MAX_COUNT][LOG] = { 0, };


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		std::cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	level[1] = 1;
	parent[1][0] = 0;
	std::queue<int> q;
	q.push(1);
	while (false == q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto& next : tree[curr])
		{
			if (0 == level[next])
			{
				level[next] = level[curr] + 1;
				parent[next][0] = curr;
				q.push(next);
			}
		}
	}

	for (int i = 1; i < LOG; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (0 != parent[j][i - 1])
			{
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
			}
		}
	}



	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;

		if (level[a] < level[b])
		{
			std::swap(a, b);
		}

		for (int k = LOG - 1; k >= 0 ; k--)
		{
			if (level[a] - (1 << k) >= level[b])
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