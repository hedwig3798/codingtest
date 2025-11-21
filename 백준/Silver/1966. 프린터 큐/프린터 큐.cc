#include <bits/stdc++.h>
#include <unordered_set>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);


	int tc;
	std::cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		int N, M;
		std::cin >> N >> M;

		std::queue<std::pair<int, int>> q;
		std::vector<int> priorityCount(10, 0);

		int maxPriority = 1;
		for (int i = 0; i < N; ++i)
		{
			int priority;
			std::cin >> priority;

			q.push({ priority, i });
			priorityCount[priority]++;
			maxPriority = std::max(maxPriority, priority);
		}

		int order = 1;
		while (false == q.empty())
		{
			std::pair<int, int> curr = q.front();
			q.pop();
			int priority = curr.first;
			int number = curr.second;

			if (priority == maxPriority)
			{
				if (number == M)
				{
					std::cout << order << "\n";
					break;
				}

				priorityCount[maxPriority]--;
				while (0 == priorityCount[maxPriority])
				{
					maxPriority--;
				}
				order++;
			}
			else
			{
				q.push(curr);
			}
		}
	}

	return 0;
}