#include <bits/stdc++.h>
using namespace std;

int backracking(int n, vector<int> &able, int now, int depth, int how) {
	int result = INT_MAX / 2;

	if (depth == how) {
		return result;
	}

	now = now * 10;
	depth++;

	for (auto i : able) {
		// cout << abs(n - (now + i)) + depth << ' ' << now + i << ' ' << depth << endl;
		result = min(result, abs(n - (now + i)) + depth);
		result = min(result, backracking(n, able, now+i, depth, how));
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string sn;
	cin >> sn;
	int n = stoi(sn);
	int how = sn.length();

	int m = 0;
	cin >> m;

	vector<int> able;
	vector<bool> disable (10, false);
	if (m != 0) {
		for (int i = 0; i < m; i++) {
			int temp = 0;
			cin >> temp;
			disable[temp] = true;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (!disable[i]) {
			able.push_back(i);
		}
	}

	int worst = abs(100 - n);

	if (m == 10) {
		cout << worst << endl;
		return 0;
	}

	cout << min(backracking(n, able, 0, 0, how+1), worst) << endl;

	

	return 0;
} 