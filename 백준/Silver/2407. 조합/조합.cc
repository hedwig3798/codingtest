#include <bits/stdc++.h>

using namespace std;

string add(string a, string b) {
	string result = "";

	bool upper = false;
	for (;!a.empty() && !b.empty();) {
		char aa = a.back();
		char bb = b.back();
		char sum = aa + bb - ('0' * 2);

		if (upper)
			sum++;
		if (sum >= 10)
			upper = true;
		else
			upper = false;

		sum %= 10;
		result.push_back(sum + '0');
		a.pop_back();
		b.pop_back();
	}
	string temp;
	if (a.empty() && b.empty()) {
		if (upper)
			result.push_back('1');
		reverse(result.begin(), result.end());
		return result;
	}
	else if (a.empty())
		temp = b;
	else if (b.empty()) 
		temp = a;
	
	for (;!temp.empty();) {
		char sum = temp.back() - '0';
		if (upper)
			sum++;
		else {
			result.push_back(temp.back());
			temp.pop_back();
			continue;
		}
		if (sum >= 10)
			upper = true;
		else
			upper = false;

		sum %= 10;
		result.push_back(sum + '0');
		temp.pop_back();
	}
	if (upper)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<string>> combiantion(n + 1, vector<string>(n + 1, "0"));

	for (int i = 1; i <= n; i++) {
		combiantion[i][i] = "1";
		combiantion[i][0] = "1";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j)
				continue;
			combiantion[i][j] = add(combiantion[i - 1][j], combiantion[i - 1][j - 1]);
		}
	}
	cout << combiantion[n][m];
	return 0;
} 