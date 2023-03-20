#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int ,vector<int>, cmp> pq;

	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;

		if (order == 0) {
			if (pq.empty()) {
				cout << '0' << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(order);
		}
	}

	return 0;
} 