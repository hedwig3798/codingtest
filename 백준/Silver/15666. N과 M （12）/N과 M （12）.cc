#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

void PrintSequence(vector<int> &sortedNumbers, vector<int> &isPrint, int m, int start){
	if (isPrint.size() == m) {
		for (int i = 0; i < isPrint.size(); i++) {
			cout << isPrint[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < sortedNumbers.size(); i++) {
		isPrint.push_back(sortedNumbers[i]);
		PrintSequence(sortedNumbers, isPrint, m, i);
		isPrint.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	set<int> numbers;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		numbers.insert(temp);
	}

	vector<int>sortedNumbers;
	vector<int> isPrint;
	for(auto i : numbers) {
		sortedNumbers.push_back(i);
	}

	sort(sortedNumbers.begin(), sortedNumbers.end());

	PrintSequence(sortedNumbers, isPrint, m, 0);

	return 0;
}