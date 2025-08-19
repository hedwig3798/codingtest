#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, M;

char classRoom[301][301];
int isVisit[301][301] = { 0, };

pii start;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	for (int i = 0; i < N; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			classRoom[i][j] = s[j];
			if (s[j] == '*')
			{
				start = { i, j };
			}
		}
	}

	std::deque<pii> dq;
	dq.push_back(start);
	isVisit[start.first][start.second] = 1;

	while (!dq.empty())
	{
		pii curr = dq.front();
		dq.pop_front();

		int cx = curr.first;
		int cy = curr.second;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0
				|| nx >= N
				|| ny < 0
				|| ny >= M
				|| 0 != isVisit[nx][ny])
			{
				continue;
			}

			if (classRoom[nx][ny] == '#')
			{
				std::cout << isVisit[cx][cy];
				return 0;
			}
			else if (classRoom[nx][ny] == '0')
			{
				dq.push_front({ nx, ny });
				isVisit[nx][ny] = isVisit[cx][cy];
			}
			else if (classRoom[nx][ny] == '1')
			{
				dq.push_back({ nx, ny });
				isVisit[nx][ny] = isVisit[cx][cy] + 1;
			}
		}
	}

	return 0;
}