#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NUM 1'001

int N, M;
std::vector<int> workers[MAX_NUM];
std::vector<int> jobs[MAX_NUM];

int left[MAX_NUM];
int right[MAX_NUM];
bool checked[MAX_NUM];

bool Link(int _worker)
{
	for(const auto& job : workers[_worker])
	{
		if (true == checked[job])
		{
			continue;
		}

		checked[job] = true;

		if (-1 == right[job] || Link(right[job]))
		{
			right[job] = _worker;
			left[_worker] = job;
			return true;
		}
	}

	return false;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int count;
		std::cin >> count;

		for (int j = 1; j <= count; ++j)
		{
			int job;
			std::cin >> job;
			workers[i].push_back(job);
			jobs[job].push_back(i);
		}
	}

	std::fill(left, left + MAX_NUM, -1);
	std::fill(right, right + MAX_NUM, -1);
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		std::fill(checked, checked + MAX_NUM, false);
		if (true == Link(i))
		{
			ans++;
		}
	}

	std::cout << ans;

	return 0;
}