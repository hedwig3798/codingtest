#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push({ num, i });
	}

	vector<int> result(n, 0);

	int standard = pq.top().first;
	int now = 0;
	for (; !pq.empty();) {
		if (pq.top().first == standard) {
			result[pq.top().second] = now;
		}
		else {
			result[pq.top().second] = ++now;
			standard = pq.top().first;
		}
		pq.pop();
	}

	for (auto i : result) {
		cout << i << ' ';
	}

	return 0;
} 