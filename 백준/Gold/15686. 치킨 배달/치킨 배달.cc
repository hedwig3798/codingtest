#include <bits/stdc++.h>
using namespace std;


int backtraking(int how, int now, vector<pair<int, int>>& chicken, vector<pair<int, int>>& house, vector<bool>& isVisit, int depth) {
	int result = INT_MAX / 2;
	if (how == depth) {
		int sum = 0;
		for (auto h : house) {
			int dis = INT_MAX/2;
			for (int i = 0; i < isVisit.size(); i++) {
				if (isVisit[i]) {
					dis = min(dis, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
					
				}
			}
			
			sum += dis;
		}
		return sum;
	}

	for (int i = now; i < chicken.size(); i++) {
		if (isVisit[i])
			continue;
		isVisit[i] = true;
		result = min(backtraking(how, i + 1, chicken, house, isVisit, depth+1), result);
		isVisit[i] = false;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<pair<int, int>> chicken;
	vector<pair<int, int>> house;
	vector<bool> isVisit;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cin >> board[i][j];

			if (board[i][j] == 2) {
				chicken.push_back({ i, j });
				isVisit.push_back(false);
			}
			else if (board[i][j] == 1)
				house.push_back({ i,j });
		}
	}
	cout << backtraking(m, 0, chicken, house, isVisit, 0);

	return 0;
}