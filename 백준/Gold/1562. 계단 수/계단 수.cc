#include <bits/stdc++.h>

using namespace std;

int dp[10][101][1 << 10];
int N;
const int DIV = 1000000000;

int dfs(int _number, int _digit, int _bit)
{
	if (dp[_number][_digit][_bit] != 0)
	{
		return dp[_number][_digit][_bit];
	}

	if (_digit == N)
	{
		if (_bit == 1023)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int temp = 0;
	if (_number < 9)
	{
		temp += dfs(_number + 1, _digit + 1, (_bit | 1 << (_number + 1)));
	}
	if (_number > 0)
	{
		temp += dfs(_number - 1, _digit + 1, (_bit | 1 << (_number - 1)));
	}

	temp %= DIV;
	dp[_number][_digit][_bit] = temp;
	return temp;
}

int main()
{
	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

	cin >> N;

	int result = 0;
	for (int i = 1; i < 10; i++)
	{
		result += dfs(i, 1, 1 << i);
		result %= DIV;
	}

	cout << result;

	return 0;
}