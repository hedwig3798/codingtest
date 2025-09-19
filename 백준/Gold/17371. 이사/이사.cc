#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

double Distance(pii& _a, pii& _b)
{
	return std::pow(_a.first - _b.first, 2) + std::pow(_a.second - _b.second, 2);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int N;
	std::vector<pii> coords;

	std::cin >> N;

	for (int i = 0; i < N ; i++)
	{
		int x, y;
		std::cin >> x >> y;
		coords.push_back({ x,y });
	}

	pii ans{0, 0};
	double minDis = le9;
	for (int i = 0; i < N; i++)
	{
		double maxDis = 0;
		for(int j = 0; j < N; j++)
		{
			maxDis = std::max(maxDis, Distance(coords[i], coords[j]));
		}

		if (minDis > maxDis)
		{
			minDis = maxDis;
			ans = coords[i];
		}
	}

	std::cout << ans.first << ' ' << ans.second;

	return 0;
}