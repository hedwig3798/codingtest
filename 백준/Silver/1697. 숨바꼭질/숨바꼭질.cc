#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	vector<int> isVisit(100001, -1);
	queue<int> q;

	isVisit[n] = 0;
	q.push(n);

	for (;;) {
		int now = q.front();
		q.pop();

		if (now * 2 == k || now + 1 == k || now - 1 == k) {
			cout << isVisit[now] + 1;
			break;
		}
		
		if (now * 2 <= 100000 && isVisit[now * 2] == -1) {
			q.push(now * 2);
			isVisit[now * 2] = isVisit[now] + 1;
		}
		if (now + 1 <= 100000 && isVisit[now + 1] == -1) {
			q.push(now + 1);
			isVisit[now + 1] = isVisit[now] + 1;
		}
		if (now - 1 > 0 && isVisit[now - 1] == -1) {
			q.push(now - 1);
			isVisit[now - 1] = isVisit[now] + 1;
		}

	}
	return 0;
} 