#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	vector<int> isVisit(n + 1, -1);

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	isVisit[0] = 0;
	isVisit[1] = 0;
	queue<int> q;
	q.push(1);

	for(;!q.empty();) {
		int now = q.front();
		q.pop();

		for (int c : tree[now]){
			if (isVisit[c] == -1) {
				isVisit[c] = now;
				q.push(c);
			}
		}
	}

	for (int i = 2; i < n+1; i++) {
		cout << isVisit[i] << '\n';
	}

	return 0;
}