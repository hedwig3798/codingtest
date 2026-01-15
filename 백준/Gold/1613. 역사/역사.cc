#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_NUM 401

int n, k;
bool history[MAX_NUM][MAX_NUM];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> k;

	for (int i = 0; i < k ; i++)
	{
		int to, from;
		std::cin >> to >> from;
		history[to][from] = true;
	}

	for (int k = 1; k <= n ; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (true == history[i][k] && true == history[k][j])
				{
					history[i][j] = true;
				}
			}
		}
	}

	int s;
	std::cin >> s;
	for (int i = 0; i < s ; i++)
	{
		int a, b;
		std::cin >> a >> b;
		if (true == history[a][b])
		{
			std::cout << -1 << '\n';
		}
		else if (true == history[b][a])
		{
			std::cout << 1 << '\n';
		}
		else
		{
			std::cout << 0 << '\n';
		}
	}

	return 0;
}