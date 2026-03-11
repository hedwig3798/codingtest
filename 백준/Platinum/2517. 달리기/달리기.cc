#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_N 500'001

ll segTree[MAX_N * 2];
ll N;

ll seq[MAX_N];
ll sortedSeq[MAX_N];

void Update(ll _target)
{
	segTree[_target + N] = 1;
	for (_target += N; _target > 1; _target >>= 1)
	{
		segTree[_target >> 1]++;
	}
}

ll Query(ll _left, ll _right)
{
	ll res = 0;
	for (_left += N, _right += N; _left < _right; _left >>= 1, _right >>= 1)
	{
		if (_left & 1)
		{
			res += segTree[_left];
			_left++;
		}
		if (_right & 1)
		{
			_right--;
			res += segTree[_right];
		}
	}

	return res;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> seq[i];
		sortedSeq[i] = seq[i];
	}

	std::sort(sortedSeq, sortedSeq + N);

	for (int i = 0; i < N; ++i)
	{
		ll curr = 0;

		ll left = 0;
		ll right = N - 1;
		while (left < right)
		{
			ll mid = (left + right) / 2;
			if (sortedSeq[mid] < seq[i])
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		curr = left;
		ll forward = Query(0, curr);
		std::cout << i + 1 - forward << '\n';
		Update(curr);
	}

	return 0;
}