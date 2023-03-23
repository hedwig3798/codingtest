#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int truth;
	cin >> truth;
	if (truth == 0) {
		cout << m;
		return 0;
	}
	vector<bool> know(n + 1, false);

	queue<int> q;

	for (int i = 0; i < truth; i++) {
		int p;
		cin >> p;

		know[p] = true;
		q.push(p);
	}

	vector<vector<int>> party(m);

	for (int i = 0; i < m; i++) {
		int count;
		cin >> count;

		for (int j = 0; j < count; j++) {
			int who;
			cin >> who;
			party[i].push_back(who);
		}
	}

	vector<vector<int>> group(n+1);

	for (auto pa : party) {
		if (pa.size() == 1)
			continue;
		for (int i = 0; i < pa.size()-1; i++) {
			group[pa[i]].push_back(pa[i + 1]);
			group[pa[i + 1]].push_back(pa[i]);
		}
	}

	for (; !q.empty();) {
		int now = q.front();
		q.pop();

		for (auto i : group[now]) {
			if (know[i])
				continue;
			know[i] = true;
			q.push(i);
		}
	}


	int answer = 0;
	for (auto p : party) {
		bool canLie = true;
		for (auto person : p) {
			if (know[person]) {
				canLie = false;
				break;
			}
		}
		if (canLie)
			answer++;
	}
	cout << answer;
	return 0;
} 