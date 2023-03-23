#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	unordered_map<string, string> hash;

	for (int i = 0; i < n; i++) {
		string name, pw;
		cin >> name >> pw;

		hash[name] = pw;
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		cout << hash[name] << '\n';
	}

	return 0;
} 