#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int limit = 100001;
	vector<int> dp(limit * 2, -1);
	dp[n] = 0;
	deque<int> q;
	q.push_front(n);

	for (; !q.empty();) {
		int now = q.front();
		q.pop_front();
		if (now == k) {
			break;
		}
		if (now * 2 <= limit && dp[now * 2] == -1) {
			dp[now * 2] = dp[now];
			q.push_front(now * 2);
		}
		if (now - 1 >= 0 && dp[now - 1] == -1) {
			dp[now - 1] = dp[now] + 1;
			q.push_back(now - 1);
		}
		if (now + 1 <= limit && dp[now + 1] == -1) {
			dp[now + 1] = dp[now] + 1;
			q.push_back(now + 1);
		}

	}
	cout << dp[k];
	return 0;
}