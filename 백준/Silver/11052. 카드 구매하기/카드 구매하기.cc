#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_COUNT 1'001

int N;
int cards[MAX_COUNT] = { 0, };
int dp[MAX_COUNT] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		std::cin >> cards[i];
	}

	for (int i = 1; i <= N ; i++)
	{
		dp[i] = cards[i];
		for (int j = 0; j < i ; j++)
		{
			dp[i] = std::max(dp[i], dp[j] + dp[i - j]);
		}
	}

	std::cout << dp[N];

	return 0;
}