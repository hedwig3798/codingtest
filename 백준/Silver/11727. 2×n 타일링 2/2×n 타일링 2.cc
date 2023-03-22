#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> dp(1001, 0);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < 1001; i++) {
		dp[i] += (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10'007;
	}

	cout << dp[n];

	return 0;
} 