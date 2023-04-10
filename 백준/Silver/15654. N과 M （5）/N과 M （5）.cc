#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> sequence(n);
	vector<int> which(n, 0);
	vector<vector<int>> result;
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	sort(sequence.begin(), sequence.end());

	for (int i = 0; i < m; i++) {
		which[i] = 1;
	}

	do {
		vector<int> temp;
		for (int i = 0; i < n; i++) {
			if (which[i] == 1){
				temp.push_back(sequence[i]);
			}
		}
		do {
			result.push_back(temp);
		} while (next_permutation(temp.begin(), temp.end()));
	} while (prev_permutation(which.begin(), which.end()));

	sort(result.begin(), result.end());

	for (auto i : result){
		for (auto c : i){
			cout << c << ' ';
		}
		cout << '\n';
	}

	return 0;
}