#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NUM 1'000

int N;
int seq[MAX_NUM];
int dp[MAX_NUM];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> seq[i];
		dp[i] = seq[i];
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (seq[i] > seq[j])
			{
				dp[i] = std::max(dp[i], dp[j] + seq[i]);
			}
		}
		ans = std::max(ans, dp[i]);
	}

	std::cout << ans;

	return 0;
}