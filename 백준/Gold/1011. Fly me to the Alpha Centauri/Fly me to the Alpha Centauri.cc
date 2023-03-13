#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int count = 0;
	cin >> count;

	for (int i = 0; i < count; i++) {
		long long start, end;
		cin >> start >> end;
		long long distance = end - start;	

		long long ind = 0;

		for (ind; distance > ind * (ind + 1); ind++) {
		}

		if (distance <= ind*ind)
			cout << ind * 2 - 1;
		else
			cout << ind * 2;
		cout << endl;
	}

	return 0;
}