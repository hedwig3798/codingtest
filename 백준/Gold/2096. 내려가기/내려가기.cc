#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int maxnow[3] = { 0, };
	int maxold[3] = { 0, };

	int minnow[3] = { 0, };
	int minold[3] = { 0, };
	cin >> maxold[0] >> maxold[1] >> maxold[2];
	minold[0] = maxold[0]; minold[1] = maxold[1]; minold[2] = maxold[2];

	for (int i = 1; i < n; i++) {
		cin >> maxnow[0] >> maxnow[1] >> maxnow[2];
		minnow[0] = maxnow[0]; minnow[1] = maxnow[1]; minnow[2] = maxnow[2];

		int temp = 0;
		maxnow[0] += max(maxold[0], maxold[1]);
		temp = max(maxold[0], maxold[1]);
		temp = max(temp, maxold[2]);
		maxnow[1] += temp;
		maxnow[2] += max(maxold[2], maxold[1]);
		maxold[0] = maxnow[0]; maxold[1] = maxnow[1]; maxold[2] = maxnow[2];

		minnow[0] += min(minold[0], minold[1]);
		temp = min(minold[0], minold[1]);
		temp = min(temp, minold[2]);
		minnow[1] += temp;
		minnow[2] += min(minold[2], minold[1]);
		minold[0] = minnow[0]; minold[1] = minnow[1]; minold[2] = minnow[2];
	}

	int maxS;
	int minS;

	maxS = max(maxold[0], maxold[1]);
	maxS = max(maxS, maxold[2]);

	minS = min(minold[0], minold[1]);
	minS = min(minS, minold[2]);

	cout << maxS << ' ' << minS;
} 