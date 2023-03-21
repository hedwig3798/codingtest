#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	long long dp[101] = { 0, };

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;

	for (int i = 5; i < 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int tc = 0; tc < t; tc++) {
		long long ind;
		cin >> ind;
		cout << dp[ind - 1] << '\n';
	}
	return 0;
} 