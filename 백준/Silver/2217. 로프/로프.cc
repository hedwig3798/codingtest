#include <bits/stdc++.h>
#include <unordered_set>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int N;
	std::cin >> N;

	std::vector<int> ropes(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> ropes[i];
	}

	std::sort(ropes.begin(), ropes.end());

	int maxW = 0;
	for (int i = 0; i < N; ++i)
	{
		maxW = std::max(maxW, ropes[i] * (N - i));
	}

	std::cout << maxW;

	return 0;
}