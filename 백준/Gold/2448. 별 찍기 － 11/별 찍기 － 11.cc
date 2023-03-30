#include <bits/stdc++.h>

using namespace std;

void draw(vector<vector<int>> &starTree, int size, pair<int, int> top) {
	if (size == 1)
		return;

	int startPoint = size / 2;
	int ind = 1;
	for (int i = startPoint; i < size; i++) {
		for (int j = 0 + ind; j <= (i*2) - ind; j++) {
			starTree[i + top.first][j + top.second] = 0;
		}
		ind += 2;
	}

	draw(starTree, size / 2, top);
	draw(starTree, size / 2, { top.first + size / 2, top.second});
	draw(starTree, size / 2, { top.first + size / 2, top.second + size });

}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> starTree;

	for (int i = 0; i < n; i++) {
		starTree.push_back(vector<int>(i * 2 + 1, 1));
	}

	draw(starTree, n, { 0, 0 });

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			cout << " ";
		}
		for (int s : starTree[i]) {
			if (s == 1)
				cout << "*";
			else
				cout << " ";
		}
		for (int j = 0; j < n - i - 1; j++) {
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
} 