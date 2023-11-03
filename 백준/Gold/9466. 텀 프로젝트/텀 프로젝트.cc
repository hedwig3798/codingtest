#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

void DFS(vector<int>& graph, vector<bool>& isTeam, vector<bool>& isVisit, vector<bool>& isDone, int node, int& result)
{
	isVisit[node] = true;
	int next = graph[node];

	if (!isVisit[next])
	{
		DFS(graph, isTeam, isVisit, isDone, next, result);
	}
	else if (!isDone[next])
	{
		for (int i = next; i != node; i = graph[i])
		{
			result++;
		}
		result++;
	}
	isDone[node] = true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		vector<int> graph(n + 1, 0);

		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[j];
		}

		vector<bool> isTeam(n + 1, false);
		vector<bool> isDone(n + 1, false);
		vector<bool> isVisit(n + 1, false);
		int result = 0;

		for (int j = 1; j < n + 1; j++)
		{
			if (isVisit[j])
			{
				continue;
			}
			DFS(graph, isTeam, isVisit, isDone, j, result);
		}
		cout << n - result << "\n";
	}

	return 0;
}