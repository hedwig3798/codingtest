#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<priority_queue<int, vector<int>, less<int>>> player(12);

	for (int i = 1; i <= 11; i++)
	{
		player[i].push(0);
	}

	for (int i = 0; i < N; i++)
	{
		int num, cost;
		cin >> num >> cost;
		player[num].push(cost);
	}

	for (int i = 0; i < K; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (player[j].top() != 0)
			{
				int temp = player[j].top();
				player[j].pop();
				player[j].push(temp - 1);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= 11; i++)
	{
		result += player[i].top();
	}

	cout << result;

	return 0;
}