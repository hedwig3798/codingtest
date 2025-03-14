#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;

int mountain[500][500];
int DP[500][500] = { 0, };


int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };


int DFS(int _x, int _y)
{
	if (_x == N - 1 && _y == M - 1)
	{
		return 1;
	}
	if (DP[_x][_y] != -1)
	{
		return DP[_x][_y];
	}

	DP[_x][_y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1)
		{
			continue;
		}

		if (mountain[_x][_y] > mountain[nx][ny])
		{
			DP[_x][_y] = DP[_x][_y] + DFS(nx, ny);
		}
	}

	return DP[_x][_y];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> mountain[i][j];
			DP[i][j] = -1;
		}
	}

	cout << DFS(0, 0);

	return 0;
}