#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> triangle(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			int number;
			cin >> number;
			triangle[i].push_back(number);
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	cout << triangle[0][0];
} 