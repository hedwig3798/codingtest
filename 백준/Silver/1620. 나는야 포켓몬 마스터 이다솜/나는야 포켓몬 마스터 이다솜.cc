#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> searchForString;
	map<int, string> searchForInteger;
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		searchForString.insert({ s, i + 1 });
		searchForInteger.insert({ i + 1, s });
	}


	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (isdigit(s[0])) {
			int a = stoi(s);
			cout << searchForInteger[a] << '\n';
		}
		else {
			cout << searchForString[s] << '\n';
		}
	}

	return 0;
} 