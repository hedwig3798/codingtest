#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_NUM 1'001

int N, M;

struct things
{
	int V, C, K;
};

std::vector<things> T;

int dp[10'001] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		things t;

		std::cin >> t.V >> t.C >> t.K;
		for (int j = t.K; j > 0; j >>= 1)
		{
			int count = j - (j >> 1);

			things trunk;
			trunk.V = t.V * count;
			trunk.C = t.C * count;
			trunk.K = count;

			T.push_back(trunk);
		}
	}


	for (auto& itr : T)
	{
		for (int i = M; i >= 0; i--)
		{
			if (itr.V <= i)
			{
				dp[i] = std::max(dp[i], dp[i - itr.V] + itr.C);
			}
		}
	}

	std::cout << dp[M];

	return 0;
}