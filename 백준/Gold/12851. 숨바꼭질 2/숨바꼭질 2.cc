#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int limits = 100001;
	

	vector<bool> isVisit(limits, false);
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	isVisit[n] = true;
	int count = 0;
	int time = 0;

	for(;!q.empty();) {
		pair<int, int> now = q.front();
		q.pop();
		isVisit[now.first] = true;

		if (count == 0 && now.first == k){
			time = now.second;
			count++;
		}
		else if (count != 0 && now.first == k && now.second == time) {
			count++;
		}

		if (now.first * 2 < limits && !isVisit[now.first * 2]) {
			q.push({ now.first * 2, now.second + 1 });
		}
		if (now.first + 1 < limits && !isVisit[now.first + 1]) {
			q.push({ now.first + 1, now.second + 1 });
		}
		if (now.first - 1 >= 0 && !isVisit[now.first - 1]) {
			q.push({ now.first - 1, now.second + 1 });
		}

		
	}
	cout << time << '\n' << count;
	return 0;
}