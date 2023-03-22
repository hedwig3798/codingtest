#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int m;
	cin >> m;

	bool s[21] = {0, };
	for (int i = 0; i < m; i++) {
		string order;
		cin >> order;
		int num;
		if (order.compare("add") == 0) {
			cin >> num;
			s[num] = true;
		}
		else if (order.compare("remove") == 0) {
			cin >> num;
			s[num] = false;
		}
		else if (order.compare("check") == 0) {
			cin >> num;
			if (s[num]) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (order.compare("toggle") == 0) {
			cin >> num;
			s[num] = !s[num];
		}
		else if (order.compare("all") == 0) {
			for (int i = 1; i < 21; i++) {
				s[i] = 1;
			}
		}
		else if (order.compare("empty") == 0) {
			for (int i = 1; i < 21; i++) {
				s[i] = 0;
			}
		}

	}

	return 0;
} 