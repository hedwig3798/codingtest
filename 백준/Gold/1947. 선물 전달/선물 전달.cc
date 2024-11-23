#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>

#define INF 1e9
#define MOD = 1'000'000'000;
typedef long long ll;

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<ll> dp(max(3, N + 1));

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	if (N >= 3)
	{
		for (int i = 3; i < N + 1; i++)
		{
			dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1'000'000'000;
		}
	}

	cout << dp[N];

	return 0;
}