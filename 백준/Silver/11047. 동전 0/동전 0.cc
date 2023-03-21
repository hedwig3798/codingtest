#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	int count = 0;
	for (int i = coins.size() - 1; i >= 0; i--) {
		if(coins[i] > k)
			continue;

		int coinCount = k / coins[i];
		count += coinCount;
		k -= coins[i] * coinCount;
		if (k == 0)
			break;
	}
	cout << count;
	return 0;
} 