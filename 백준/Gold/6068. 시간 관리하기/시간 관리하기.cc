#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::priority_queue<pii> pq;

	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t, s;
		std::cin >> t >> s;

		pq.push({ s, t });
	}

	pii block = { le9, le9 };

	while (false == pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		int cs = curr.first;
		int ct = curr.second;

		if (cs <= block.first)
		{
			block.second = cs;
			block.first = cs - ct;
		}
		else if (cs > block.first)
		{
			block.first -= ct;
		}

		if (block.first < 0)
		{
			std::cout << -1;
			return 0;
		}
	}

	std::cout << block.first;

	return 0;
}