#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> bag(n+1);
	vector<int> dp(k+1, 0);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		bag[i] = { a,b };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = k; j > 0; j--) {
			if (j >= bag[i].first) {
				dp[j] = max(dp[j - bag[i].first] + bag[i].second, dp[j]);
			}
		}
	}

	cout << dp.back() << endl;

	return 0;
}