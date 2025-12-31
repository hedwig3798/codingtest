#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_NUM 1'001

int N, M;
int mars[MAX_NUM][MAX_NUM];
int dp[MAX_NUM][MAX_NUM] = { 0, };
int LR[MAX_NUM] = { 0, };
int RL[MAX_NUM] = { 0, };


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> mars[i][j];
		}
	}

	dp[0][0] = mars[0][0];
	for (int i = 1; i < M ; i++)
	{
		dp[0][i] = dp[0][i - 1] + mars[0][i];
	}

	for (int i = 1; i < N ; i++)
	{
		LR[0] = dp[i - 1][0] + mars[i][0];
		for (int j = 1; j < M ; j++)
		{
			LR[j] = std::max(dp[i - 1][j], LR[j - 1]) + mars[i][j];
		}

		RL[M - 1] = dp[i - 1][M - 1] + mars[i][M - 1];
		for (int j = M - 2; j >= 0; j--)
		{
			RL[j] = std::max(dp[i - 1][j], RL[j + 1]) + mars[i][j];
		}

		for (int j = 0; j < M ; j++)
		{
			dp[i][j] = std::max(LR[j], RL[j]);
		}
	}

	std::cout << dp[N - 1][M - 1];

	return 0;
}