#include <bits/stdc++.h>
#include <unordered_set>

#define MAX_NUM 200'001

int N, C;

int houses[MAX_NUM];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> C;
	for (int i = 0; i < N ; i++)
	{
		std::cin >> houses[i];
	}

	std::sort(houses, houses + N);

	int left = 1;
	int right = houses[N - 1] - houses[0];
	int ans = 0;

	while (left <= right)
	{
		int count = 1;
		int mid = (right + left) / 2;
		int start = houses[0];

		for (int i = 1; i < N ; i++)
		{
			if (houses[i] - start >= mid)
			{
				count++;
				start = houses[i];
			}
		}

		if (count >= C)
		{
			ans = std::max(ans, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	std::cout << ans;

	return 0;
}