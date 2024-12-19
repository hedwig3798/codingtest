#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <limits.h> 
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;

int N;
vector<vector<int>> pipes(128, vector<int>(128, 0));
vector<vector<int>> flows(128, vector<int>(128, 0));


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char start, end;
		int water;

		cin >> start >> end >> water;
		pipes[start][end] += water;
		pipes[end][start] += water;
	}

	int totalFlow = 0;

	while (true)
	{
		vector<int> parent(128, -1);
		queue<int> q;
		parent['A'] = 'A';
		q.push('A');

		while (!q.empty() && parent['Z'] == -1)
		{
			int curr = q.front();
			q.pop();

			for (int i = 0; i < 128; i++)
			{
				if (pipes[curr][i] == 0)
				{
					continue;
				}

				if (pipes[curr][i] - flows[curr][i] > 0 && parent[i] == -1)
				{
					q.push(i);
					parent[i] = curr;
				}
			}
		}

		if (parent['Z'] == -1)
		{
			break;
		}

		int amount = INF;

		for (int p = 'Z'; p != 'A'; p = parent[p])
		{
			amount = min(pipes[parent[p]][p] - flows[parent[p]][p], amount);
		}

		for (int p = 'Z'; p != 'A'; p = parent[p])
		{
			flows[parent[p]][p] += amount;
			flows[p][parent[p]] -= amount;
		}

		totalFlow += amount;
	}

	cout << totalFlow;

	return 0;
}