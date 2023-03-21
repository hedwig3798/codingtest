#include <bits/stdc++.h>

using namespace std;

int gdc(int a, int b) {
	int c = 0;
	for (; b != 0;) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gdc(a, b);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	

	for (int i = 0; i < t; i++) {
		bool can = false;
		int n, m, x, y;
		cin >> n >> m >> x >> y;

		for (int cx = x; cx <= lcm(n, m); cx += n) {
			int temp = (cx % m == 0) ? m : cx % m;
			if (temp == y) {
				cout << cx << '\n';
				can = true;
				break;
			}
		}
		if (!can) {
			cout << -1 << '\n';
		}
	}

	return 0;
} 