#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	vector<int> dp(k + 1, 1000000);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
		dp[coin[i]] = 1;
	}

	sort(coin.begin(), coin.end());
	dp[0] = 0;

	for (int i = 1; i < k + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}

	if (dp[k] >= 1000000)
	{
		cout << -1;
		return 0;
	}

	cout << dp[k];

	return 0;
}