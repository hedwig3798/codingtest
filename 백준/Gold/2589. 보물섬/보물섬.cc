#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int H, W;
	cin >> H >> W;

	vector<string> treasureMap;

	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < H; i++)
	{
		string s;
		cin >> s;
		treasureMap.push_back(s);
	}

	stack<pair<int, int>> sp;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (treasureMap[i][j] == 'L')
			{
				sp.push({ i,j });
			}
		}
	}

	int longest = 0;

	while (!sp.empty())
	{
		vector<vector<int>> isVisit(H, vector<int>(W, -1));
		queue<pair<int, int>> q;

		q.push(sp.top());
		isVisit[sp.top().first][sp.top().second] = 0;
		sp.pop();

		while (!q.empty())
		{
			auto now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = now.first + dx[i];
				int ny = now.second + dy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W 
					|| treasureMap[nx][ny] == 'W' || isVisit[nx][ny] != -1)
				{
					continue;
				}

				q.push({ nx, ny });
				isVisit[nx][ny] = isVisit[now.first][now.second] + 1;
				longest = max(longest, isVisit[nx][ny]);
			}
		}
	}

	cout << longest;
}