#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	vector<int> minus;

	int now = 0;
	int old = 0;

	for (char c : s) {
		if (c == '+') {
			old += now;
			now = 0;
		}
		else if (c == '-') {
			old += now;
			minus.push_back(old);
			old = 0;
			now = 0;
		}
		else {
			now = now * 10 + (c - '0');
		}
	}
	minus.push_back(old + now);
	int sub = minus[0];

	for (int i = 1; i < minus.size(); i++) {
		sub -= minus[i];
	}
	cout << sub;

	return 0;
} 