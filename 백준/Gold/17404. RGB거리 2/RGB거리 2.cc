#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

struct House
{
	int rgb[3];
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<House> houses(N);
	vector<House> dp(N);

	for (int i = 0; i < N; i++)
	{
		cin >> houses[i].rgb[0];
		cin >> houses[i].rgb[1];
		cin >> houses[i].rgb[2];
	}

	int result = 1e9;

	for (int j = 0; j < 3; j++)
	{
		dp[0].rgb[0] = 1e9;
		dp[0].rgb[1] = 1e9;
		dp[0].rgb[2] = 1e9;

		dp[0].rgb[j] = houses[0].rgb[j];

		for (int i = 1; i < N; i++)
		{
			dp[i] = houses[i];
			dp[i].rgb[0] += min(dp[i - 1].rgb[1], dp[i - 1].rgb[2]);
			dp[i].rgb[1] += min(dp[i - 1].rgb[0], dp[i - 1].rgb[2]);
			dp[i].rgb[2] += min(dp[i - 1].rgb[1], dp[i - 1].rgb[0]);
		}

		switch (j)
		{
		case 0:
			result = min(result, min(dp[N - 1].rgb[1], dp[N - 1].rgb[2]));
			break;
		case 1:
			result = min(result, min(dp[N - 1].rgb[0], dp[N - 1].rgb[2]));
			break;
		case 2:
			result = min(result, min(dp[N - 1].rgb[1], dp[N - 1].rgb[0]));
			break;
		default:
			break;
		}
	}

	cout << result;
	return 0;
}