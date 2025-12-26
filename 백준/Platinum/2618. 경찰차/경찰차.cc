#include <bits/stdc++.h>
#include <unordered_set>

int N, W;

int dp[1'001][1'001];

std::pair<int, int> cases[1001];

std::vector<int> ans;

int GetDis(std::pair<int, int> _a, std::pair<int, int> _b)
{
	return abs(_a.first - _b.first) + abs(_a.second - _b.second);
}

int DP(int _a, int _b)
{
	if (-1 != dp[_a][_b])
	{
		return dp[_a][_b];
	}

	int nextCase = std::max(_a, _b) + 1;
	if (nextCase > W)
	{
		return 0;
	}

	int aDis, bDis;
	if (_a == 0)
	{
		aDis = GetDis({ 1, 1 }, cases[nextCase]);
	}
	else
	{
		aDis = GetDis(cases[_a], cases[nextCase]);
	}

	if (_b == 0)
	{
		bDis = GetDis({ N, N }, cases[nextCase]);
	}
	else
	{
		bDis = GetDis(cases[_b], cases[nextCase]);
	}

	int aResult = aDis + DP(nextCase, _b);
	int bResult = bDis + DP(_a, nextCase);

	dp[_a][_b] = std::min(aResult, bResult);

	return dp[_a][_b];
}

void Trace(int _a, int _b)
{
	int nextCase = std::max(_a, _b) + 1;
	if (nextCase > W)
	{
		return;
	}

	int aDis, bDis;
	if (_a == 0)
	{
		aDis = GetDis({ 1, 1 }, cases[nextCase]);
	}
	else
	{
		aDis = GetDis(cases[_a], cases[nextCase]);
	}

	if (_b == 0)
	{
		bDis = GetDis({ N, N }, cases[nextCase]);
	}
	else
	{
		bDis = GetDis(cases[_b], cases[nextCase]);
	}

	if (dp[nextCase][_b] + aDis < dp[_a][nextCase] + bDis)
	{
		std::cout << "1\n";
		Trace(nextCase, _b);
	}
	else
	{
		std::cout << "2\n";
		Trace(_a, nextCase);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> W;

	for (int i = 1; i <= W; i++)
	{
		std::cin >> cases[i].first >> cases[i].second;
	}

	memset(dp, -1, sizeof(dp));

	std::cout << DP(0, 0) << '\n';

	Trace(0, 0);

	return 0;
}