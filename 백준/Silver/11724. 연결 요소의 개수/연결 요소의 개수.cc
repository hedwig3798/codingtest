#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	vector<bool>isVisit(n + 1, false);
	isVisit[0] = true;
	int count = 0;
	for (int i = 1; i < n + 1; i++) {
		if (!isVisit[i]) {
			count++;
			
			queue<int> q;
			q.push(i);
			isVisit[i] = true;
			for (; !q.empty();) {
				int now = q.front();
				q.pop();

				for (auto g : graph[now]) {
					if (!isVisit[g]) {
						isVisit[g] = true;
						q.push(g);
					}
				}
			}

		}
	}
	cout << count;
	return 0;
} 