#include <bits/stdc++.h>

using namespace std;

struct cmp
{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0 && pq.empty()) {
			cout << 0 << '\n';
		}
		else if (x == 0) {
			cout << pq.top() << '\n';
			pq.pop();
		}
		else {
			pq.push(x);
		}
	}
	return 0;
} 