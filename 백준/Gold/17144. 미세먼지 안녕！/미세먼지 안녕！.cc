#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>

#define INF 1e9
#define MOD 1'000'000'000;
typedef long long ll;

using namespace std;

int R, C, T;

vector<vector<int>> dust;

vector<int> air;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void Diffuse()
{
	vector<vector<int>> dustDiffuse(R, vector<int>(C, 0));;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (dust[i][j] <= 0)
				continue;

			int diff = dust[i][j] / 5;
			int diffCount = 0;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || dust[nx][ny] == -1)
				{
					continue;
				}
				diffCount++;
				dustDiffuse[nx][ny] += diff;
			}
			dustDiffuse[i][j] += dust[i][j] - (diff * diffCount);
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (dust[i][j] == -1)
			{
				continue;
			}
			dust[i][j] = dustDiffuse[i][j];
		}
	}
}

void Wind()
{
	int left = 0;
	int top = 0;
	int right = C - 1;
	int bottom = air[0];

	for (int i = bottom - 1; i > top ; i--)
		dust[i][left] = dust[i - 1][left];

	for (int i = left; i < right; i++)
		dust[top][i] = dust[top][i + 1];

	for (int i = top; i <= bottom; i++)
		dust[i][right] = dust[i + 1][right];

	for (int i = right; i > left + 1; i--)
		dust[bottom][i] = dust[bottom][i - 1];

	dust[bottom][left + 1] = 0;


	left = 0;
	top = air[1];
	right = C - 1;
	bottom = R - 1;

	for (int i = top + 1; i < bottom; i++)
		dust[i][left] = dust[i + 1][left];

	for (int i = left; i < right; i++)
		dust[bottom][i] = dust[bottom][i + 1];

	for (int i = bottom; i >= top; i--)
		dust[i][right] = dust[i - 1][right];

	for (int i = right; i > left + 1; i--)
		dust[top][i] = dust[top][i - 1];

	dust[top][left + 1] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> T;

	dust = vector<vector<int>>(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> dust[i][j];
			if (dust[i][j] == -1)
			{
				air.push_back(i);
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		Diffuse();
		Wind();
	}

	int ans = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ans += dust[i][j];
		}
	}

	cout << ans + 2;

	return 0;
}