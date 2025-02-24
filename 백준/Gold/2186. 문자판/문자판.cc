#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

vector<string> board;

int N, M, K;
string target;

char first;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void DFS(queue<pii>& _q, vector<vector<int>>& prevPath)
{
	if (target.length() == 0)
	{
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == first)
				{
					ans += prevPath[i][j];
				}
			}
		}
		cout << ans;
		return;
	}

	vector<vector<int>> pathCount = vector<vector<int>>(N, vector<int>(M, 0));

	queue<pii> next;

	while (!_q.empty())
	{
		pii now = _q.front();
		_q.pop();

		for (int j = 1; j <= K; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = now.first + dx[i] * j;
				int ny = now.second + dy[i] * j;

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				{
					continue;
				}

				if (board[nx][ny] == target.back())
				{
					if (pathCount[nx][ny] == 0)
					{
						pathCount[nx][ny] += prevPath[now.first][now.second];
						next.push({ nx, ny });
					}
					else
					{
						pathCount[nx][ny] += prevPath[now.first][now.second];
					}
				}
			}
		}
	}

	target.pop_back();
	prevPath.clear();
	DFS(next, pathCount);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int ans = 0;

	cin >> N >> M >> K;
	board.resize(N);

	vector<vector<int>> pathCount = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	cin >> target;

	first = target[0];

	queue<pii> initq;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c = target.back();
			if (board[i][j] == c)
			{
				pathCount[i][j] = 1;
				initq.push({ i, j });
			}
		}
	}

	target.pop_back();

	DFS(initq, pathCount);

	return 0;
}