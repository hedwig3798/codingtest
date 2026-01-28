#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 101

int N;
int cost[MAX_COUNT] = { 0, };
int checked[MAX_COUNT] = { 0, };
bool isScc[MAX_COUNT] = { 0, };
bool isVisit[MAX_COUNT] = { 0, };

std::vector<int> cities[MAX_COUNT];

std::stack<int> s;
int cnt = 0;

int ans = 0;

int DFS(int _curr)
{
	s.push(_curr);
	checked[_curr] = cnt;
	int p = cnt;
	cnt++;

	for (auto& next : cities[_curr])
	{
		if (-1 == checked[next])
		{
			p = std::min(p, DFS(next));
		}
		else if (false == isScc[next])
		{
			p = std::min(p, checked[next]);
		}
	}

	if (p == checked[_curr])
	{
		int lowest = INT_MAX;
		while (true)
		{
			int t = s.top();
			s.pop();
			isScc[t] = true;
			lowest = std::min(lowest, cost[t]);
			if (t == _curr)
			{
				break;
			}
		}
		ans += lowest;
	}

	return p;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		std::cin >> cost[i];
		checked[i] = -1;
	}

	for (int i = 0; i < N; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < N; j++)
		{
			if ('1' == s[j])
			{
				cities[i + 1].push_back(j + 1);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (-1 == checked[i])
		{
			DFS(i);
		}
	}

	std::cout << ans;

	return 0;
}