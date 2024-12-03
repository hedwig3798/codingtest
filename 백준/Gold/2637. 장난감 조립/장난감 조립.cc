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
#define MOD 100'000;
typedef long long ll;

using namespace std;

vector<vector<int>> component;
vector<int> inDegree;
vector<vector<int>> outDegree;
vector<bool> isBasic;
int N;
int M;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	component = vector<vector<int>>(N + 1, vector<int>(N + 1));
	inDegree = vector<int>(N + 1, 0);
	outDegree = vector<vector<int>>(N + 1);
	isBasic = vector<bool>(N + 1, true);
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int X, Y, K;
		cin >> X >> Y >> K;

		component[X][Y] += K;
		inDegree[X]++;
		outDegree[Y].push_back(X);
		isBasic[X] = false;
	}

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto& d : outDegree[curr])
		{
			--inDegree[d];

			for (int i = 1; i <= N; i++)
			{
				component[d][i] += component[curr][i] * component[d][curr];
			}
			if (!isBasic[curr])
			{
				component[d][curr] = 0;
			}

			if (inDegree[d] == 0)
			{
				q.push(d);
			}
		}
	}

	for (int i = 1; i <= N ; i++)
	{
		if (component[N][i] != 0)
		{
			cout << i << " " << component[N][i] << "\n";
		}
	}

	return 0;
}