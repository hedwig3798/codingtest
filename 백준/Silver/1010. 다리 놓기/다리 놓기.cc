#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int combi(int n , int r) {

	for (int i = 0; i < n; i++) {
		arr[i][0] = 1;
	}

	for (int j = 0; j < r; j++) {
		arr[j][j] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < r; j++) {

			arr[i][j] = arr[i - 1][j - 1] + arr[i-1][j];
		}
	}
	return arr[n][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	vector<int> b(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}

	combi(31, 31);

	for (int i = 1; i <= n; i++) {
		cout << arr[b[i]][a[i]] << endl;
	}

	return 0;
}