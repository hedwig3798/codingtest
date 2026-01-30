#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 50'001

int N, M;
std::vector<int> tree[MAX_COUNT];

int level[MAX_COUNT] = { 0, };
int parent[MAX_COUNT] = { 0, };

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
	parent[1] = 0;
	std::queue<int> q;
	q.push(1);
	while (false == q.empty())
	{
		int curr = q.front();
		q.pop();

		for(auto& next : tree[curr])
		{
			if (0 == level[next])
			{
				level[next] = level[curr] + 1;
				parent[next] = curr;
				q.push(next);
			}
		}
	}

	std::cin >> M;
	for (int i = 0; i < M ; i++)
	{
		int a, b;
		std::cin >> a >> b;

		if (level[a] < level[b])
		{
			std::swap(a, b);
		}

		int sub = level[a] - level[b];

		while (0 < sub)
		{
			a = parent[a];
			sub--;
		}

		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}

		std::cout << a << '\n';
	}

	return 0;
}