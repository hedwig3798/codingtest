#include <bits/stdc++.h>
using namespace std;

long long getMod(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}

	long long k = getMod(a, b / 2, c) % c;
	if (b % 2 == 0) {
		return k * k % c;
	}
	else {
		return k * k % c * a % c;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << getMod(a, b, c);
	
	return 0;
} 