#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_CITY 10'000

int dp[MAX_CITY + 1][2];
int citizen[MAX_CITY + 1];
bool isVisit[MAX_CITY + 1];
int N;

std::vector<std::vector<int>> city;

void DFS(int _now)
{
	isVisit[_now] = true;

	dp[_now][0] = 0;
	dp[_now][1] = citizen[_now];

	for(auto next : city[_now])
	{
		if (true == isVisit[next])
		{
			continue;
		}

		DFS(next);

		dp[_now][0] += std::max(dp[next][0], dp[next][1]);
		dp[_now][1] += dp[next][0];
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	city.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> citizen[i];
	}

	for (int i = 0; i < N - 1 ; i++)
	{
		int a, b;
		std::cin >> a >> b;

		city[a].push_back(b);
		city[b].push_back(a);
	}

	DFS(1);

	std::cout << std::max(dp[1][0], dp[1][1]);

	return 0;
}