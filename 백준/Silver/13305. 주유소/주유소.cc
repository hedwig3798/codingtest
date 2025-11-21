#include <bits/stdc++.h>
#include <unordered_set>

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	std::vector<long long> length(N - 1);
	std::vector<long long> cost(N);

	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> length[i];
	}

	for (int i = 0; i < N ; ++i)
	{
		std::cin >> cost[i];
	}

	long long minCost = INT_MAX;
	int ans = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		minCost = std::min(minCost, cost[i]);
		ans += minCost * length[i];
	}

	std::cout << ans;

	return 0;
}