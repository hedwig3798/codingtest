#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NUM 1'000

int N;
int seq[MAX_NUM];

std::vector<int> ans;

int BS(int _target)
{
	int left = 0;
	int right = ans.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;

		if (ans[mid] <= _target)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> seq[i];
	}

	ans.push_back(seq[0]);
	for (int i = 1; i < N; ++i)
	{
		if (seq[i] < ans.back())
		{
			ans.push_back(seq[i]);
			continue;
		}

		int ind = BS(seq[i]);
		ans[ind] = seq[i];
	}

	std::cout << ans.size();

	return 0;
}