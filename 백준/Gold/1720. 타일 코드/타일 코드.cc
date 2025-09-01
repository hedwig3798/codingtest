#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int dp[31];
int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N ; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
	}

	if (0 == N % 2)
	{
		std::cout << (dp[N] + dp[N / 2] + (dp[(N / 2) - 1] * 2)) / 2;
	}
	else
	{
		std::cout << (dp[N] + dp[(N- 1) / 2]) / 2;
	}

	return 0;
}