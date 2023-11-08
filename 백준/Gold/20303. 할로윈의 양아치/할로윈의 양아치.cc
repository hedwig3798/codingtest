#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

#define INF 1e9
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> candy(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> candy[i];
	}

	vector<vector<int>> fr(N + 1, vector<int>());
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}

	vector<int> w;
	vector<int> v;
	w.push_back(0);
	v.push_back(0);

	vector<int> isVisit(N + 1, false);

	int maxCandy = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!isVisit[i])
		{
			queue<int> q;
			q.push(i);
			isVisit[i] = true;

			int stole = candy[i];
			int child = 1;

			while (!q.empty())
			{
				int now = q.front();
				q.pop();

				for(auto& c : fr[now])
				{
					if (!isVisit[c])
					{
						child++;
						stole += candy[c];
						q.push(c);
						isVisit[c] = true;
					}
				}
			}

			if (child >= K) 
			{
				continue;
			}
			w.push_back(child);
			v.push_back(stole);
			maxCandy += stole;
		}
	}

	if (w.size() == 0) 
	{
		cout << 0;
		return 0;
	}

	vector<vector<int>> dp(w.size() , vector<int>(K, 0));
	for (int i = 1; i < w.size(); i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (j >= w[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[w.size() - 1][K - 1];

	return 0;
}