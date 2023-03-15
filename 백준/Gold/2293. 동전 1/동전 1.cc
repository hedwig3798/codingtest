#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	vector<int> kind(k + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin.begin(), coin.end());
	kind[0] = 1;
	
	for (auto c : coin) {
		for (int i = c; i <= k; i++) {
			kind[i] += kind[i - c];
		}
	}

	cout << kind[k];

	return 0;
}