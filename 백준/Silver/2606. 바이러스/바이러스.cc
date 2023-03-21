#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> network(n + 1);
	vector<bool> isVirus(n + 1, false);
	int m;
	cin >> m;



	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		network[a].push_back(b);
		network[b].push_back(a);
	}

	isVirus[1] = true;

	queue<int> q;
	q.push(1);

	for (; !q.empty();) {
		int now = q.front();
		q.pop();

		for (auto computer : network[now]) {
			if (isVirus[computer])
				continue;
			isVirus[computer] = true;
			q.push(computer);
		}
	}

	int count = 0;
	for (auto v : isVirus) {
		if (v)
			count++;
	}

	cout << count - 1;

	return 0;
} 