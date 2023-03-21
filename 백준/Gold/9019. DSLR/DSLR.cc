#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		int a, b;
		cin >> a >> b;

		pair<int, string> com_a = { a, "" };
		bool isVisit[10000] = { 0, };
		queue<pair<int, string>> q;
		q.push(com_a);

		for (;;) {
			pair<int, string> now = q.front();
			q.pop();

			int mul = (now.first * 2) % 10000;
			int sub = (now.first - 1 < 0) ? 9999 : now.first - 1;
			int left = now.first * 10;
			left += left / 10000;
			left = left % 10000;
			int right = (now.first / 10) + ((now.first % 10) * 1000);
			
			if (mul == b) {
				cout << now.second + "D" << '\n';
				break;
			}
			if (left == b) {
				cout << now.second + "L" << '\n';
				break;
			}
			if (right == b) {
				cout << now.second + "R" << '\n';
				break;
			}
			if (sub == b) {
				cout << now.second + "S" << '\n';
				break;
			}

			if (!isVisit[mul]) {
				q.push({ mul, now.second + "D" });
				isVisit[mul] = 1;
			}
			if (!isVisit[left]) {
				q.push({ left, now.second + "L" });
				isVisit[left] = 1;
			}if (!isVisit[right]) {
				q.push({ right, now.second + "R" });
				isVisit[right] = 1;
			}if (!isVisit[sub]) {
				q.push({ sub, now.second + "S" });
				isVisit[sub] = 1;
			}
		}
	}

	return 0;
} 