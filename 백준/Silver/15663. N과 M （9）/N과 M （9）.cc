#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	set<vector<int>> storage;

	vector<int> numbers;
	vector<int> subvector(n, 0);

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		subvector[i] = 1;
	}
	sort(numbers.begin(), numbers.end());

	do {
		do {
			vector<int> temp;
			for (int i = 0; i < n; i++) {
				if (subvector[i] == 1) {
					temp.push_back(numbers[i]);
				}
			}
			storage.insert(temp);
		} while (prev_permutation(subvector.begin(), subvector.end()));
	} while (next_permutation(numbers.begin(), numbers.end()));
    
	vector<vector<int>> result;
	for(auto s : storage) {
		result.push_back(s);
	}

	sort(result.begin(), result.end());

	for(auto r : result) {
		for(auto i : r) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}