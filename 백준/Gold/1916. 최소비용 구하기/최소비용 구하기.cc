#include <bits/stdc++.h>
using namespace std;

struct cmp
{
	bool operator()(pair<int ,int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> route(n+1);

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;

		route[a].push_back({ b, cost });

	}
	int start, end;
	cin >> start >> end;

	int dik[1001];

	for (int i = 0; i < n+1; i++) {
		dik[i] = INT_MAX / 2;
	}
	dik[start] = 0;


	priority_queue <pair<int, int>> pq;
	pq.push({ start, 0 });

	for (; !pq.empty();) {
		pair<int, int> now = pq.top();
		pq.pop();
		int cdis = -now.second;
		int cpoint = now.first;

		if (dik[cpoint] < cdis)
			continue;

		for (auto i : route[now.first]) {
			int npoint = i.first;
			int ndis = cdis + i.second;

			if (ndis < dik[npoint]) {
				dik[npoint] = ndis;
				pq.push({ npoint, -ndis });
			}
		}
	}
	cout << dik[end] << "\n";

	return 0;
} 