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

	int dx[] = { 1, 1, 1, -1, -1, -1, 0, 0};
	int dy[] = { 0, 1, -1, 0, 1, -1, 1, -1};

	while (true)
	{
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)
		{
			break;
		}

		vector<vector<int>>landMap(h, vector<int>(w, 0));
		vector<vector<bool>>isVisit(h, vector<bool>(w, false));


		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int num;
				cin >> num;
				landMap[i][j] = num;
			}
		}

		int islandCount = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (isVisit[i][j])
				{
					continue;
				}
				if (landMap[i][j] == 0)
				{
					isVisit[i][j] = true;
					continue;
				}
				if (landMap[i][j] == 1)
				{
					islandCount++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					isVisit[i][j] = true;

					while (!q.empty())
					{
						auto now = q.front();
						q.pop();

						for (int k = 0; k < 8; k++)
						{
							int nx = now.first + dx[k];
							int ny = now.second + dy[k];

							if (nx < 0 || nx >= h || ny < 0 || ny >= w) 
							{
								continue;
							}
							if (isVisit[nx][ny])
							{
								continue;
							}
							if (landMap[nx][ny] == 0)
							{
								continue;
							}
							if (landMap[nx][ny] == 1)
							{
								landMap[nx][ny] = 0;
								q.push({ nx, ny });
							}
						}
					}
				}
			}
		}

		cout << islandCount << "\n";
	}
	return 0;
}