#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	long long N, K;
	cin >> N >> K;

	vector<vector<long long>>dp(201, vector<long long>(201, 0));

	for (int i = 0; i < 201; i++)
	{
		dp[1][i] = 1;
	}

	for (int k = 2; k <= K; k++)
	{
		for (int n = 0; n <= N; n++)
		{
			for (int i = 0; i <= n; i++)
			{
				dp[k][n] += dp[k - 1][i];
			}
			dp[k][n] %= 1'000'000'000;
		}
	}

	cout << dp[K][N];
}