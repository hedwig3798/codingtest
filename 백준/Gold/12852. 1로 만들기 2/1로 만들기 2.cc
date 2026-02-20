#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

int N;
std::vector<int> parent;

void PrintAns()
{
	std::vector<int> ans;
	ans.push_back(1);

	while (N != ans.back())
	{
		ans.push_back(parent[ans.back()]);
	}

	std::cout << ans.size() - 1 << '\n';

	for (int i = ans.size() - 1; i >= 0; --i)
	{
		std::cout << ans[i] << ' ';
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	parent.resize(N + 1, -1);

	std::queue<int> q;
	q.push(N);
	parent[N] = 0;

	while (false == q.empty())
	{
		int curr = q.front();
		q.pop();

		if (1 == curr)
		{
			PrintAns();
			return 0;
		}

		if (0 == curr % 3)
		{
			int div = curr / 3;
			if (-1 == parent[div])
			{
				parent[div] = curr;
				q.push(div);
				if (1 == div)
				{
					PrintAns();
					return 0;
				}
			}
		}

		if (0 == curr % 2)
		{
			int div = curr / 2;
			if (-1 == parent[div])
			{
				parent[div] = curr;
				q.push(div);
				if (1 == div)
				{
					PrintAns();
					return 0;
				}
			}
		}

		int sub = curr - 1;
		if (-1 == parent[sub])
		{
			parent[sub] = curr;
			q.push(sub);
			if (1 == sub)
			{
				PrintAns();
				return 0;
			}
		}
	}

	return 0;
}