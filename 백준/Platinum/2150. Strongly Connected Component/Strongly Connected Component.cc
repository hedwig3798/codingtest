#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_V 10'001

int V, E;

std::vector<int> graph[MAX_V];
int labels[MAX_V] = { 0, };
std::stack<int> s;
bool isSCC[MAX_V] = { 0, };
int label = 1;

std::vector<std::set<int>> ans;

int SCC(int _now)
{
	s.push(_now);
	labels[_now] = label;
	int result = label;
	label++;

	for(auto& next : graph[_now])
	{
		if (0 == labels[next])
		{
			result = std::min(result, SCC(next));
		}
		else if (false == isSCC[next])
		{
			result = std::min(result, labels[next]);
		}
	}

	if (result == labels[_now])
	{
		ans.push_back({});
		std::set<int>& scc = ans.back();

		while (true)
		{
			int t = s.top();
			s.pop();

			scc.insert(t);
			labels[t] = result;
			isSCC[t] = true;
			if (t == _now)
			{
				break;
			}
		}
	}

	return result;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int A, B;
		std::cin >> A >> B;
		graph[A].push_back(B);
	}

	for (int i = 1; i <= V ; i++)
	{
		if (0 == labels[i])
		{
			SCC(i);
		}
	}

	std::cout << ans.size() << '\n';

	std::sort(ans.begin(), ans.end());

	for(auto& a : ans)
	{
		for(auto& n : a)
		{
			std::cout << n << ' ';
		}	
		std::cout << -1 << '\n';
	}

	return 0;
}