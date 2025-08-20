#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int ind = 1;

	while (true)
	{
		int N;
		std::cin >> N;

		if (0 == N)
		{
			return 0;
		}

		std::vector<std::vector<int>> cave(N, std::vector<int>(N, 0));
		std::vector<std::vector<int>> cost(N, std::vector<int>(N, le9));

		for (int i = 0; i < N ; i++)
		{
			for (int j = 0; j < N ; j++)
			{
				std::cin >> cave[i][j];
			}
		}

		pii start = { 0, 0 };
		std::priority_queue<std::tuple<int, int, int>> pq;
		cost[0][0] = cave[0][0];
		pq.push({ -cost[0][0], 0, 0 });

		while (false == pq.empty())
		{
			auto currNode = pq.top();
			pq.pop();

			int cc = -std::get<0>(currNode);
			int cx = std::get<1>(currNode);
			int cy = std::get<2>(currNode);

			for (int i = 0; i < 4 ; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0
					|| nx >= N
					|| ny < 0
					|| ny >= N)
				{
					continue;
				}

				int nc = cc + cave[nx][ny];
				if (cost[nx][ny] > nc)
				{
					cost[nx][ny] = nc;
					pq.push({ -nc, nx, ny });
				}
			}
		}
		std::cout << "Problem " << ind++ << ": " << cost[N - 1][N - 1] << "\n";
	}


	return 0;
}