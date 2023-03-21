#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> waiting(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> waiting[i];
	}
	sort(waiting.begin(), waiting.end());

	int waitingTime = 0;
	for (int i = 0; i < n; i++) {
		waitingTime += waiting[i] * (n - i);
	}
	cout << waitingTime;
	return 0;
} 