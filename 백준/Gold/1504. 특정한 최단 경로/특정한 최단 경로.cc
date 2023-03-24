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

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> nRoute(n + 1);

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		nRoute[start].push_back({ end,cost });
		nRoute[end].push_back({ start,cost });
	}
	int p1, p2;
	cin >> p1 >> p2;

	vector<int> g1(n + 1);
	vector<int> g2(n + 1);
	vector<int> g3(n + 1);
	g1 = dik(nRoute, 1, n);
	g2 = dik(nRoute, p1, n);
	g3 = dik(nRoute, p2, n);
	if (g1[p1] >= INT_MAX / 2 || g1[p2] >= INT_MAX / 2 || g1[n] >= INT_MAX / 2)
		cout << -1;
	else {
		int answer = g1[p1] + g2[p2] + g3[n];
		answer = min(answer, g1[p2] + g3[p1] + g2[n]);
		cout << answer;
	}
	
	return 0;
} 