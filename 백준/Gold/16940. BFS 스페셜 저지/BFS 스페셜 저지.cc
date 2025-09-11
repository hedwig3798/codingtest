#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;
std::vector<int> order;

bool cmp(const int& _a, const int& _b)
{
	return order[_a] < order[_b];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	std::vector<std::vector<int>> bfs(N + 1);
	order.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		std::cin >> a >> b;
		bfs[a].push_back(b);
		bfs[b].push_back(a);
	}

	for (int i = 0; i < N ; i++)
	{
		int a;
		std::cin >> a;
		order[a] = i + 1;
	}

	if (order[1] != 1)
	{
		std::cout << 0;
		return 0;
	}

	for (int i = 1; i <= N; i++)
	{
		std::sort(bfs[i].begin(), bfs[i].end(), cmp);
	}

	std::queue<int> q;
	std::vector<bool> isVist(N + 1, false);
	q.push(1);
	isVist[1] = true;
	int index = 2;

	while (false == q.empty())
	{
		int curr = q.front();
		q.pop();

		for(auto next : bfs[curr])
		{
			if (true == isVist[next])
			{
				continue;
			}

			if (order[next] == index)
			{
				isVist[next] = true;
				q.push(next);
				++index;
			}
			else
			{
				std::cout << 0;
				return 0;
			}
		}
	}

	std::cout << 1;

	return 0;
}