#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;

	vector<int> dp(12, 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++) {
		for (int j = 1; j < 4; j++) {
			dp[i] += dp[i - j];
		}
	}

	for (int tc = 0; tc < t; tc++) {
		int ind;
		cin >> ind;
		cout << dp[ind] << '\n';
	}

	return 0;
} 