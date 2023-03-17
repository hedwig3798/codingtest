#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, c, r;
	cin >> n >> r >> c;

	int s = (int)pow(2, n);
	int w = s * s;
	pair<int, int> start = { 0, 0 };
	pair<int, int> end = { s - 1, s - 1 };
	int answer = 0;
	for (; w != 1;) {
		bool isLeft, isTop;

		pair<int, int> mid = { (start.first + (end.first - start.first) / 2) , (start.second + (end.second - start.second) / 2) };
		isLeft = (c <= (mid.second));
		isTop = (r <= (mid.first));
// 		cout << start.first << ' ' << start.second << '\n';
// 		cout << end.first << ' ' << end.second << '\n';
// 		cout << mid.first << ' ' << mid.second << '\n';
// 		cout << isLeft << ' ' << isTop << '\n';
// 		cout << '\n';
		w /= 4;
		if (isLeft && isTop) {
			end = mid;
		}
		else if (!isLeft && isTop) {
			start.second = mid.second + 1;
			end.first = mid.first;
			answer += w * 1;
		}
		else if (isLeft && !isTop) {
			start.first = mid.first+1;
			end.second = mid.second;
			answer += w * 2;
		}
		else if (!isLeft && !isTop) {
			start = { mid.first + 1, mid.second + 1 };
			answer += w * 3;
		}
	}
	cout << answer << '\n';
	return 0;
} 