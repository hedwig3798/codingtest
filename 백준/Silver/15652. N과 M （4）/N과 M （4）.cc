#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

void printSequence(int n, int m, vector<int> &prints, int start) {
	if (prints.size() == m) {
		for(auto p : prints) {
			cout << p << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		prints.push_back(i + 1);
		printSequence(n, m, prints, i);
		prints.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> prints;

	printSequence(n, m, prints, 0);

	return 0;
}