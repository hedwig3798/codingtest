#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> sequence(n);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			
		}
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}