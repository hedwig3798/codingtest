#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> dp(n + 1, { 0,0 });

	for (int i = 1; i < n + 1; i++) {
		int now = i;
		int d2 = 0;
		int d5 = 0;

		for (; now % 2 == 0;) {
			d2++;
			now = now / 2;
		}

		for (; now % 5 == 0;) {
			d5++;
			now = now / 5;
		}

		dp[i] = { dp[i - 1].first + d2, dp[i - 1].second + d5 };
	}
	cout << min(dp[n].first, dp[n].second);
	return 0;
} 