#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

#define INF 1e9
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<string> board(N);
	vector<vector<bool>> isVisit(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	int result = 0;
	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	char dc[] = { 'L', 'U', 'R', 'D' };


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!isVisit[i][j])
			{
				result++;
				int ud = i;
				int lr = j;
				queue<pair<int, int>> q;
				q.push({ ud ,lr });

				while (!isVisit[ud][lr])
				{
					isVisit[ud][lr] = true;
					if (board[ud][lr] == 'D')
					{
						ud++;
						q.push({ ud ,lr });
					}
					else if (board[ud][lr] == 'U')
					{
						ud--;
						q.push({ ud ,lr });
					}
					else if (board[ud][lr] == 'L')
					{
						lr--;
						q.push({ ud ,lr });
					}
					else if (board[ud][lr] == 'R')
					{
						lr++;
						q.push({ ud ,lr });
					}
				}
				isVisit[i][j] = true;

				while (!q.empty())
				{
					int ud = q.front().first;
					int lr = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int nud = ud + dy[k];
						int nlr = lr + dx[k];

						if (nud < 0 || nud >= N || nlr < 0 || nlr >= M) 
						{
							continue;
						}

						if (!isVisit[nud][nlr] && board[nud][nlr] == dc[k])
						{
							q.push({ nud, nlr });
							isVisit[nud][nlr] = true;
						}
					}

				}
			}
		}
	}

	cout << result;

	return 0;
}