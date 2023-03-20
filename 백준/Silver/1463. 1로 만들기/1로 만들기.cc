#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> dp(n + 1);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i < n + 1; i++) {
		int can2 = INT_MAX / 2;
		int can3 = INT_MAX / 2;
		
		if (i % 2 == 0) {
			can2 = dp[i / 2];
		}
		if (i % 3 == 0) {
			can3 = dp[i / 3];
		}

		dp[i] = min(can2, can3);
		dp[i] = min(dp[i], dp[i - 1]);
		dp[i]++;
	}

	cout << dp[n];

	return 0;
} 