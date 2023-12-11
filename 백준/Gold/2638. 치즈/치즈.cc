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

int N, M;

int cheese[100][100];
bool isVisit[100][100];
int airCount[100][100];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	pair<int, int> sPoint;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> cheese[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	isVisit[0][0] = true;

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	int ans = 0;
	bool isMelt = true;
	while (isMelt)
	{
		isMelt = false;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			int cx = cur.first;
			int cy = cur.second;

			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				{
					continue;
				}
				if (isVisit[nx][ny])
				{
					continue;
				}

				if (cheese[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					isVisit[nx][ny] = true;
				}
				else if (cheese[nx][ny] == 1)
				{
					airCount[nx][ny]++;
					isMelt = true;
				}
			}
		}

		if (isMelt)
		{
			ans++;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (airCount[i][j] >= 2 && cheese[i][j] == 1)
					{
						cheese[i][j] = 0;
						q.push(make_pair(i, j));
						isVisit[i][j] = true;
					}
				}
			}
		}
	}

	cout << ans;
}