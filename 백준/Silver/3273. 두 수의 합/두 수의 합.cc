#include <bits/stdc++.h>
#include <unordered_set>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int N, x;
	std::cin >> N;

	if (1 >= N)
	{
		std::cout << 0;
		return 0;
	}

	std::vector<int> seq(N);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> seq[i];
	}

	std::cin >> x;

	std::sort(seq.begin(), seq.end());

	int ans = 0;
	int left = 0;
	int right = N - 1;

	while (left < right)
	{
		int sum = seq[left] + seq[right];

		if (sum == x)
		{
			ans++;
			left++;
			right--;
		}
		else if (sum > x)
		{
			right--;
		}
		else if (sum < x)
		{
			left++;
		}
	}

	std::cout << ans;

	return 0;
}