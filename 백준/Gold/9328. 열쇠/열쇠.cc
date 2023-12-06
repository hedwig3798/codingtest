#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <memory.h>

#define INF (int)1e9
using namespace std;

int T, h, w;

char board[100][100];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> h >> w;
		queue<pair<int, int>> q;
		vector<vector<bool>> isVisit(h, vector<bool>(w, false));
		vector<bool> hasKey('z' - 'a' + 1, false);
		vector<stack<pair<int, int>>> door('Z' - 'A' + 1, stack<pair<int, int>>());
		int ans = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				{
					if (board[i][j] == '.')
					{
						q.push(make_pair(i, j));
						isVisit[i][j] = true;
					}
					else if (board[i][j] >= 'A' && board[i][j] <= 'Z')
					{
						door[board[i][j] - 'A'].push(make_pair(i, j));
					}
					else if (board[i][j] >= 'a' && board[i][j] <= 'z')
					{
						hasKey[board[i][j] - 'a'] = true;
						q.push(make_pair(i, j));
						isVisit[i][j] = true;
					}
					else if (board[i][j] == '$')
					{
						ans++;
						q.push(make_pair(i, j));
						isVisit[i][j] = true;
					}

				}
			}
		}



		string key;
		cin >> key;

		if (key == "0")
		{
			key = "";
		}


		for (auto& c : key)
		{
			hasKey[c - 'a'] = true;
		}

		for (int i = 0; i < hasKey.size(); i++)
		{
			if (hasKey[i])
			{
				while (!door[i].empty())
				{
					q.push(door[i].top());
					door[i].pop();
				}
			}
		}

		int dx[] = { 1, 0, -1, 0 };
		int dy[] = { 0, 1, 0, -1 };

		while (!q.empty())
		{
			auto now = q.front();
			q.pop();

			int cx = now.first;
			int cy = now.second;

			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || ny < 0 || nx >= h || ny >= w) 
				{
					continue;
				}
				if (board[nx][ny] == '*')
				{
					continue;
				}
				if (isVisit[nx][ny])
				{
					continue;
				}

				if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z')
				{
					if (hasKey[board[nx][ny] - 'A'])
					{
						board[nx][ny] = '.';
					}
					else
					{
						door[board[nx][ny] - 'A'].push(make_pair(nx, ny));
						continue;
					}
				}

				else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z')
				{
					if (hasKey[board[nx][ny] - 'a'])
					{
						board[nx][ny] = '.';
					}
					else
					{
						hasKey[board[nx][ny] - 'a'] = true;
						while (!door[board[nx][ny] - 'a'].empty())
						{
							q.push(door[board[nx][ny] - 'a'].top());
							door[board[nx][ny] - 'a'].pop();
						}
					}
				}

				else if (board[nx][ny] == '$')
				{
					ans++;
				}

				q.push(make_pair(nx, ny));
				isVisit[nx][ny] = true;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}