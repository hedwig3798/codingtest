#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using ull = unsigned long long;

ull N, K;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> K;

	ull left = 1;
	ull right = K;

	ull ans = 0;
	while (left <= right)
	{
		ull mid = (left + right) / 2;

		ull count = 0;
		for (ull i = 1; i <= N ; i++)
		{
			count += std::min(mid / i, N);
		}

		if (count < K)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	std::cout << ans;
	return 0;
}