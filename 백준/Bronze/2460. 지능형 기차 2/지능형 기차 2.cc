#include <bits/stdc++.h>
using namespace std;
int main() {

	int now = 0;
	int answer = 0;

	for (int i = 0; i < 10; i++) {
		int out, in;
		cin >> out >> in;

		now -= out;
		now += in;

		answer = max(now, answer);
	}
	cout << answer;

	return 0;
}