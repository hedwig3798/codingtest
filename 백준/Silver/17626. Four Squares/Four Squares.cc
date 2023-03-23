#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> dp(n + 1, INT_MAX/2);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n ; i++) {
		if ((int)sqrt(i) * (int)sqrt(i) == i) {
			dp[i] = 1;
			continue;
		}

		for (int j = 1; j*j <= i/2; j++) {
			dp[i] = min(dp[i], dp[j*j] + dp[i - (j*j)]);
		}
	}
	cout << dp[n];
	return 0;
} 