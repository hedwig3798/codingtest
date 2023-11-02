#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> memory(N, 0);
	vector<int> cost(N, 0);


	for (int i = 0; i < N; i++)
	{
		cin >> memory[i];
	}
	int sumCost = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
		sumCost += cost[i];
	}

	vector<vector<int>> ns(N, vector<int>(sumCost + 1, 0));

	for (int i = cost[0]; i < sumCost + 1; i++)
	{
		ns[0][i] = memory[0];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < sumCost + 1; j++)
		{
			if (j - cost[i] >= 0)
			{
				ns[i][j] = max(ns[i][j], ns[i - 1][j - cost[i]] + memory[i]);
			}
			ns[i][j] = max(ns[i][j], ns[i - 1][j]);
		}
	}

	for (int i = 0; i < sumCost + 1; i++)
	{
		if (ns[N - 1][i] >= M)
		{
			cout << i;
			return 0;
		}
		 
	}

	return 0;
}