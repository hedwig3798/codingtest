#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> sequence(n);
	vector<int> which(n, 0);
	for (int i = 0; i < n; i++) {
		sequence[i] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		which[i] = 1;
	}

	do {
		for (int i = 0; i < n; i++) {
			if (which[i] == 1){
				cout << sequence[i] << ' ';
			}
		}
		cout << '\n';
	} while (prev_permutation(which.begin(), which.end()));

	return 0;
}