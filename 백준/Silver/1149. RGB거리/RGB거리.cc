#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>>house(n, vector<int>(3, 0));
	vector<vector<int>>dp(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		house[i] = { r, g, b };
	}
	dp[0] = house[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1] + house[i][0], dp[i - 1][2] + house[i][0]);
		dp[i][1] = min(dp[i - 1][0] + house[i][1], dp[i - 1][2] + house[i][1]);
		dp[i][2] = min(dp[i - 1][0] + house[i][2], dp[i - 1][1] + house[i][2]);
	}

	int minimun = min(dp[n - 1][0], dp[n - 1][1]);
	minimun = min(minimun, dp[n - 1][2]);

	cout << minimun;
	return 0;
} 