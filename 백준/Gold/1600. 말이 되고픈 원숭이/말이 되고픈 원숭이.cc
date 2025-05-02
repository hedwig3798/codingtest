#include <bits/stdc++.h>

#define le9 1'000'000'001
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

struct node
{
	int x, y, h;
};

int K, W, H;
int board[200][200];
int isVisit[200][200][31] = { 0, };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int hx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int hy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<node> q;
	q.push({ 0, 0, K });
	isVisit[0][0][K] = 1;
	while (!q.empty())
	{
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int nh = now.h;

			if (nx < 0 || ny < 0 || nx >= H || ny >= W || isVisit[nx][ny][nh] != 0 || board[nx][ny] == 1)
			{
				continue;
			}

			isVisit[nx][ny][nh] = isVisit[now.x][now.y][now.h] + 1;

			if (nx == H - 1 && ny == W - 1)
			{
				int a = 1;
			}
			else
			{
				q.push({ nx, ny, nh });
			}
		}

		if (now.h == 0)
		{
			continue;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = now.x + hx[i];
			int ny = now.y + hy[i];
			int nh = now.h - 1;

			if (nx < 0 || ny < 0 || nx >= H || ny >= W || isVisit[nx][ny][nh] != 0 || board[nx][ny] == 1)
			{
				continue;
			}

			isVisit[nx][ny][nh] = isVisit[now.x][now.y][now.h] + 1;

			if (nx == H - 1 && ny == W - 1)
			{
				int a = 1;
			}
			else
			{
				q.push({ nx, ny, nh });
			}
		}
	}
	int ans = le9;
	for (int i = 0; i <= K; i++)
	{
		if (isVisit[H - 1][W - 1][i] != 0)
		{
			ans = min(ans, isVisit[H - 1][W - 1][i]);
		}
	}

	if (ans == le9)
	{
		cout << -1;
	}
	else
	{
		cout << ans - 1;
	}

	return 0;
}