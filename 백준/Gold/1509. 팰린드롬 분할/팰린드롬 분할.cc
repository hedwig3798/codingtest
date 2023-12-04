#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>

#define INF (int)1e9
using namespace std;

string str;
bool dp[2501][2501];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		dp[i][i] = true;
	}

	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			dp[i][i + 1] = true;
		}
	}

	for (int i = 2; i < str.length(); i++)
	{
		for (int j = 0; j + i < str.length(); j++)
		{
			if (str[j] == str[j + i] && dp[j + 1][j + i - 1])
			{
				dp[j][j + i] = true;
			}
		}
	}

	vector<int> ans(str.length());

	for (int i = 0; i < str.length(); i++)
	{
		ans[i] = INF;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 && dp[j][i] && ans[i] > 1)
			{
				ans[i] = 1;
			}
			else if (dp[j][i] && ans[i] > ans[j - 1] + 1)
			{
				ans[i] = ans[j - 1] + 1;
			}
		}
	}

	cout << ans[str.size() - 1];

	return 0;
}