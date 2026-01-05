#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_COUNT 1'001

int N;
int dp[MAX_COUNT] = { 0, };
int reversDp[MAX_COUNT] = { 0, };
int numbers[MAX_COUNT] = { 0, };


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;



	for (int i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
		dp[i] = 1;
		reversDp[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (numbers[j] < numbers[i])
			{
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}


	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = N - 1; j > i; --j)
		{
			if (numbers[j] < numbers[i])
			{
				reversDp[i] = std::max(reversDp[i], reversDp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = std::max(ans, dp[i] + reversDp[i] - 1);
	}

	std::cout << ans;

	return 0;
}