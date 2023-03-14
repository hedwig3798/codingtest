#include <bits/stdc++.h>
using namespace std;


void dfs(vector<char>& c, int how, int now, vector<char> s, vector<bool> &check) {

	if (s.size() == how) {

		int mo = 0;
		int ja = 0;
		bool flag = false;
		for (auto i : s) {
			
			if (i == 'a' || i == 'u' || i == 'o' || i == 'i' || i == 'e')
				mo++;
			else
				ja++;
			if (mo >= 1 && ja >= 2) {
				flag = true;
				break;
			}
		}

		if (flag) {
			for (auto i : s) {
				cout << i;
			}
			cout << endl;
			return;
		}
		else {
			return;
		}
		
	}
	

	for (int i = now; i < c.size(); i++) {
		if (check[i])
			continue;
		s.push_back(c[i]);
		check[i] = true;
		dfs(c, how, i + 1, s, check);
		s.pop_back();
		check[i] = false;

	}
	return;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int L, C;
	cin >> L >> C;

	vector<char> c(C);
	vector<bool> check(C, false);

	for (int i = 0; i < C; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());

	dfs(c, L, 0, vector<char>(), check);

	return 0;
}