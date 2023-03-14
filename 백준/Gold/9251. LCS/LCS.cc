#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a;
	cin >> b;

	vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int result = 0;
	for (auto i : dp) {
		result = max(*max_element(i.begin(), i.end()), result);
	}
	cout << result;
	return 0;
}