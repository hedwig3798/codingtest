#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, M;
int dp[21][21][21] = { 0, };
int seq[20] = { 0, };

int DFS(int _ind, int _left, int _right)
{
	if (_ind == M)
	{
		return 0;
	}

	if (dp[_ind][_left][_right] != 0)
	{
		return dp[_ind][_left][_right];
	}

	int lMovement = ::abs(_left - seq[_ind]) + DFS(_ind + 1, seq[_ind], _right);
	int rMovement = ::abs(_right - seq[_ind]) + DFS(_ind + 1, _left, seq[_ind]);

	return std::min(lMovement, rMovement);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	int sLeft, sRight;
	std::cin >> sLeft >> sRight;
	std::cin >> M;

	for (int i = 0; i < M; i++)
	{
		std::cin >> seq[i];
	}

	std::cout <<  DFS(0, sLeft, sRight);

	return 0;
}