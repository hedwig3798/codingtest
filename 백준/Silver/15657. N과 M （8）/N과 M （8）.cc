#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

void printSequence(int n, int m, vector<int> &prints, int start, vector<int> &numbers) {
	if (prints.size() == m) {
		for(auto p : prints) {
			cout << p << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		prints.push_back(numbers[i]);
		printSequence(n, m, prints, i, numbers);
		prints.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> prints;
	vector<int> numbers;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	printSequence(n, m, prints, 0, numbers);

	return 0;
}