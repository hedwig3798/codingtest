#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> graph (N + 1);
	vector<int> cost(N + 1, 1e9);
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
	}

	queue<int> q;
	q.push(X);
	cost[X] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for(auto g : graph[now])
		{
			if (cost[g] > cost[now] + 1)
			{
				cost[g] = cost[now] + 1;
				q.push(g);
			}
		}
	}
	int count = 0;
	for (size_t i = 1; i < cost.size(); i++)
	{
		if (cost[i] == K)
		{
			count++;
			cout << i << "\n";
		}
	}

	if (count == 0) 
	{
		cout << -1;
	}

	return 0;
}