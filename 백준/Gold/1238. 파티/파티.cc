#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator () (pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

vector<int> dik(vector<vector<pair<int, int>>> &route, int start, int size) {
	vector<int> result(size + 1, INT_MAX / 2);

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	
	pq.push({ start, 0 });
	result[start] = 0;
	for (; !pq.empty();) {
		pair<int ,int> now = pq.top();
		int cDist = now.second;
		int cNode = now.first;
		pq.pop();

		if (cDist > result[cNode])
			continue;

		for (auto r : route[cNode]) {
			int nDist = r.second + cDist;
			int nNode = r.first;
			if (result[nNode] > nDist) {
				result[nNode] = nDist;
				pq.push({ nNode, nDist });
			}
		}
	}

	return result;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<pair<int, int>>> nRoute(n + 1);
	vector<vector<pair<int, int>>> rRoute(n + 1);

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		nRoute[start].push_back({ end,cost });
		rRoute[end].push_back({ start,cost });
	}

	vector<int> go(n + 1);
	vector<int> back(n + 1);
	go = dik(nRoute, x, n);
	back = dik(rRoute, x, n);

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		answer = max(answer, go[i] + back[i]);
	}
	cout << answer;
	return 0;
} 