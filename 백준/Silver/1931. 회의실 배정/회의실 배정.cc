#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> timetbale;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		timetbale.push_back({ start, end });
	}

	sort(timetbale.begin(), timetbale.end(), cmp);
	
	int count = 0;
	int now = 0;
	for (auto t : timetbale) {
		if (count == 0){
			now = t.second;
			count++;
			continue;
		}

		if (now > t.first) {
			continue;
		}
		else {
			count++;
			now = t.second;
		}

	}
	cout << count;
	return 0;
} 