#include <bits/stdc++.h>
using namespace std;

vector<int> dik(vector<vector<pair<int, int>>> &tree, int size, int start) {
	vector<int> result(size + 1, INT_MAX / 2);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	result[start] = 0;
	result[0] = 0;

	for (; !pq.empty();) {
		int cDis = -pq.top().first;
		int cNode = pq.top().second;
		pq.pop();
		if (cDis > result[cNode])
			continue;
		for (auto t : tree[cNode]) {
			int nDis = cDis + t.second;
			int nNode = t.first;

			if (nDis < result[nNode]) {
				result[nNode] = nDis;
				pq.push({ -nDis, nNode });
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> tree(n + 1);

	for (int i = 0; i < n-1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		tree[from].push_back({ to, cost });
		tree[to].push_back({ from, cost });
	}

	vector<int> dis1 = dik(tree, n, 1);
	int startPoint = 1;
	for (int i = 1; i < n + 1; i++) {
		if (dis1[startPoint] < dis1[i]) {
			startPoint = i;
		}
	}

	vector<int> dis2 = dik(tree, n, startPoint);

	cout << *max_element(dis2.begin(), dis2.end());

} 