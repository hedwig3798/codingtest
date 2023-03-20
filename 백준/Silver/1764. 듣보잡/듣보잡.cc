#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	unordered_map <string, int> unSeen;
	vector<string> unkonw;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		unSeen[s] = 1;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (!(unSeen.find(s) == unSeen.end())) {
			unkonw.push_back(s);
		}
	}
	sort(unkonw.begin(), unkonw.end());

	cout << unkonw.size() << '\n';

	for (auto s : unkonw) {
		cout << s << '\n';
	}
	return 0;
} 