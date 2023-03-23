#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<int>board(101, 0);
	for (int i = 0; i < 101; i++) {
		board[i] = i;
	}

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		board[start] = end;
	}

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		board[start] = end;
	}
	
	queue<int> q;
	vector<int> isVist(101, -1);
	q.push(1);
	isVist[1] = 0;
	for (; !q.empty();) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			if (i + now > 100)
				continue;
			if (isVist[board[now + i]] != -1)
				continue;
			isVist[board[now + i]] = isVist[now] + 1;
			q.push(board[now + i]);
		}
	}
	cout << isVist[100];
	return 0;
} 