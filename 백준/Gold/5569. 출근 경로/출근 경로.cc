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
#define MOD 100'000;
typedef long long ll;

using namespace std;

pair<int, int> curr;

ll ans;

int w, h;

int dp[101][101][4] = {};

int ee = 0;
int en = 1;
int nn = 2;
int ne = 3;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	curr = { 1, 1 };

	cin >> w >> h;

	for (int i = 1; i <= w ; i++)
	{
		dp[i][1][ee] = 1;
	}
	for (int i = 1; i <= h ; i++)
	{
		dp[1][i][nn] = 1;
	}

	for (int i = 2; i <= w ; i++)
	{
		for (int j = 2; j <= h ; j++)
		{
			dp[i][j][ee] = (dp[i - 1][j][ee] + dp[i - 1][j][ne]) % MOD;
			dp[i][j][ne] = dp[i - 1][j][nn];
			dp[i][j][nn] = (dp[i][j - 1][nn] + dp[i][j - 1][en]) % MOD;
			dp[i][j][en] = dp[i][j - 1][ee];
		}
	}

	cout << (dp[w][h][0] + dp[w][h][1] + dp[w][h][2] + dp[w][h][3]) % MOD;

	return 0;
}