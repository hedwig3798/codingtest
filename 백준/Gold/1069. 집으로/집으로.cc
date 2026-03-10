#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

int X, Y, D, T;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> X >> Y >> D >> T;

	double distance = std::sqrt(X * X + Y * Y);

	int count = int(distance / (double)D);

	double ans = distance;

	ans = std::min(ans, (double)(T * count) + std::abs(distance - (double)(D * count)));
	if (count == 0)
	{
		ans = std::min(ans, (double)(T * (count + 1)) + std::abs(distance - (double)(D * (count + 1))));
		ans = std::min(ans, (double)(T * (count + 2)));
	}
	else
	{
		ans = std::min(ans, (double)(T * (count + 1)));
	}

	std::cout.precision(13);
	std::cout << ans;

	return 0;
}