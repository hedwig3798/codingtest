#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		map<string, int> type;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			type[b] += 1;
		}

		int sum = 1;
		for (auto i : type) {
			sum *= (i.second + 1);
		}
		cout << sum - 1 << '\n';
	}

	return 0;
} 