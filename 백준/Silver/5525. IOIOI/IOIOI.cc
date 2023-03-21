#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	vector<int> cp;
	for (int i = 0; i < m; i++) {
		if (s[i] == 'O')
			continue;
		int count = 0;
		i++;
		bool isO = true;
		for (;;) {
			if (isO && s[i] == 'O') {
				isO = false;
				i++;
			}
			else if (!isO && s[i] == 'I') {
				isO = true;
				count++;
				i++;
			}
			else {
				i--;
				break;
			}
		}
		if (count != 0)
			cp.push_back(count);
	}

	int sum = 0;
	for (auto c : cp) {
		if (c >= n) {
			sum += c - n + 1;
		}
	}
	cout << sum;
	return 0;
} 