#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;
std::vector<std::string> room;
bool isVisit[251][51][51][4] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	room.resize(N);

	pii point[2];

	int pointindex = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> room[i];

		for (int j = 0; j < N; j++)
		{
			if (room[i][j] == '#')
			{
				point[pointindex++] = { i,j };
			}
		}
	}

	// 0 -> up
	// 1 -> right
	// 2 -> down
	// 3 -> left

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	int dir = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = point[0].first + dx[i];
		int ny = point[0].second + dy[i];

		if (nx < 0
			|| ny < 0
			|| nx >= N
			|| ny >= N
			|| room[nx][ny] == '*')
		{
			continue;
		}

		dir = i;
		break;
	}

	std::priority_queue<std::vector<int>> pq;
	pq.push({ 0, point[0].first, point[0].second, dir });

	while (false == pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		int cCount = -curr[0];
		int cx = curr[1];
		int cy = curr[2];
		int cDir = curr[3];

		if (cx == point[1].first
			&& cy == point[1].second)
		{
			std::cout << cCount;
			break;
		}


		if (room[cx][cy] == '!')
		{
			int ndir1 = 0;
			int ndir2 = 0;
			int nx1, ny1, nx2, ny2;

			switch (cDir)
			{
			case 0:
			case 2:
				ndir1 = 1;
				ndir2 = 3;
				nx1 = cx + dx[ndir1];
				ny1 = cy + dy[ndir1];
				nx2 = cx + dx[ndir2];
				ny2 = cy + dy[ndir2];
				break;
			case 1:
			case 3:
				ndir1 = 0;
				ndir2 = 2;
				nx1 = cx + dx[ndir1];
				ny1 = cy + dy[ndir1];
				nx2 = cx + dx[ndir2];
				ny2 = cy + dy[ndir2];
				break;
			default:
				break;
			}

			if (nx1 < 0
				|| ny1 < 0
				|| nx1 >= N
				|| ny1 >= N
				|| room[nx1][ny1] == '*'
				|| true == isVisit[cCount + 1][nx1][ny1][ndir1])
			{
			}
			else
			{
				pq.push({ -(cCount + 1), nx1, ny1, ndir1 });
				isVisit[cCount + 1][nx1][ny1][ndir1] = true;
			}

			if (nx2 < 0
				|| ny2 < 0
				|| nx2 >= N
				|| ny2 >= N
				|| room[nx2][ny2] == '*'
				|| true == isVisit[cCount + 1][nx2][ny2][ndir2])
			{
			}
			else
			{
				pq.push({ -(cCount + 1), nx2, ny2, ndir2 });
				isVisit[cCount + 1][nx2][ny2][ndir2] = true;
			}
		}

		int nx = cx + dx[cDir];
		int ny = cy + dy[cDir];

		if (nx < 0
			|| ny < 0
			|| nx >= N
			|| ny >= N
			|| room[nx][ny] == '*'
			|| true == isVisit[cCount][nx][ny][cDir])
		{
		}
		else
		{
			pq.push({ -cCount, nx, ny, cDir });
			isVisit[cCount][nx][ny][cDir] = true;
		}
	}

	return 0;
}