#include <bits/stdc++.h>
#include <unordered_set>

long long N, L;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> L;

	std::vector<long long> seq(N + 1);
	for (long long i = 1; i <= N; i++)
	{
		std::cin >> seq[i];
	}

	std::priority_queue<std::pair<long long, long long>> minq;
	for (long long i = 1; i <= N; i++)
	{
		long long left = i - L + 1;
		long long right = i;
		if (1 == right)
		{
			std::cout << seq[i] << ' ';
			minq.push({ -seq[i], i });
			continue;
		}

		if (0 >= left)
		{
			minq.push({ -seq[right], right });
			std::cout << -minq.top().first << ' ';
		}
		else
		{
			minq.push({ -seq[right], right });
			while (minq.top().second > right 
				|| minq.top().second < left)
			{
				minq.pop();
			}
			std::cout << -minq.top().first << ' ';
		}
	}


	return 0;
}