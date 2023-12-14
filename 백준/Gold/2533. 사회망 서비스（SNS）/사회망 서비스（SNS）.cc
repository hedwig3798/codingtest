#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <memory.h>

#define INF (int)1e9
using namespace std;

int N;
vector<vector<int>> sns;
vector<vector<int>> dp;
vector<bool> isVisit;
int ans = 0;

void DFS(int _now)
{
	isVisit[_now] = true;
	dp[_now][0] = 1;

	for (int i = 0; i < sns[_now].size(); i++)
	{
		int child = sns[_now][i];
		if (isVisit[child])
		{
			continue;
		}
		DFS(child);
		dp[_now][1] += dp[child][0];
		dp[_now][0] += min(dp[child][1], dp[child][0]);
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	sns.resize(N + 1);

	dp = vector<vector<int>>(N + 1, vector<int>(2, 0));
	isVisit = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		sns[u].push_back(v);
		sns[v].push_back(u);
	}

	DFS(1);

	cout << min(dp[1][0], dp[1][1]);

	return 0;
}