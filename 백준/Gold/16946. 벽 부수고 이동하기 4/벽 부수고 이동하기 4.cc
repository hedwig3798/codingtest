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
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<string> board(N);
	vector<vector<int>> result(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	vector<vector<bool>> isVisit(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			stack<pair<int, int>> accPoint;

			if (board[i][j] == '1')
			{
				result[i][j] += 1;
			}
			else
			{
				if (isVisit[i][j])
				{
					continue;
				}
				int acc = 1;
				queue<pair<int, int>> q;
				q.push({ i, j });
				isVisit[i][j] = true;

				while (!q.empty())
				{
					auto now = q.front();
					q.pop();

					int nx = now.first;
					int ny = now.second;

					for (int k = 0; k < 4; k++)
					{
						int ox = nx + dx[k];
						int oy = ny + dy[k];

						if (ox < 0 || oy < 0 || ox >= N || oy >= M || isVisit[ox][oy])
						{
							continue;
						}

						isVisit[ox][oy] = true;
						if (board[ox][oy] == '1')
						{
							accPoint.push({ ox, oy });
						}
						else
						{
							acc++;
							q.push({ ox, oy });
						}
					}
				}
				while (!accPoint.empty())
				{
					auto now = accPoint.top();
					accPoint.pop();
					result[now.first][now.second] += acc;
					isVisit[now.first][now.second] = false;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << result[i][j] % 10;
		}
		cout << "\n";
	}

	return 0;
}