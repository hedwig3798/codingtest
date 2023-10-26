#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int Cost(int _to, int _from)
{
	if (_to == 0)
	{
		return 2;
	}
	if (_to == _from)
	{
		return 1;
	}
	if (abs(_to - _from) == 2)
	{
		return 4;
	}
	return 3;
}

int dps(vector<vector<vector<int>>>& dp, vector<int>& DDR, int l, int r, int d)
{
	if (DDR.size() == d) 
	{
		return 0;
	}
	if (dp[l][r][d] != -1)
	{
		return dp[l][r][d];
	}

	return dp[l][r][d] = min(
		dps(dp, DDR, DDR[d], r, d + 1) + Cost(l, DDR[d]),
		dps(dp, DDR, l, DDR[d], d + 1) + Cost(r, DDR[d]));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	vector<int> DDR;

	while (true)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			break;
		}
		DDR.push_back(num);
	}

	vector<vector<vector<int>>> dp(5, vector<vector<int>>(5, vector<int>(DDR.size(), -1)));

	cout << dps(dp, DDR, 0, 0, 0);

	return 0;
}