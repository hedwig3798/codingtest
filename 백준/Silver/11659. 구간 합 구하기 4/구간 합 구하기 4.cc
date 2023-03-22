#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> sequence(n, 0);
	vector<int> subSum(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	subSum[0] = 0;
	for (int i = 1; i <= n; i++) {
		subSum[i] = subSum[i - 1] + sequence[i-1];
	}

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		cout << subSum[end] - subSum[start-1] << '\n';
	}

	return 0;
} 