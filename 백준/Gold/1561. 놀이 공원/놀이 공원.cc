#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = unsigned long long;

#define MAX_N 2'000'000'000LL
#define MAX_M 10'000
#define MAX_TIME 30

ll N, M;
ll rider[MAX_M] = { 0, };

ll GetCount(ll _time)
{
	ll res = M;
	for (long long i = 0; i < M; ++i)
	{
		res += _time / rider[i];
	}

	return res;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;
	for (ll i = 0; i < M; ++i)
	{
		std::cin >> rider[i];
	}

	if (N <= M)
	{
		std::cout << N;
		return 0;
	}

	ll left = 0;
	ll right = MAX_N * MAX_TIME;
	ll ans = 0;

	while (left <= right)
	{
		ll mid = left + ((right - left) / 2);
		ll count = GetCount(mid);
		if (count < N)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	ll temp = GetCount(ans - 1);

	for (int i = 0; i < M; ++i)
	{
		if (0 == (ans % rider[i]))
		{
			temp++;
		}
		if (temp == N)
		{
			std::cout << i + 1;
			return 0;
		}
	}
	return 0;
}