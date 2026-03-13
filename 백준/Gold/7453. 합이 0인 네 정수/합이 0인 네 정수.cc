#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NUM (1 << 28)
#define MAX_N 4000


int N;
ll seq[4][MAX_N] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		ll A, B, C, D;
		std::cin >> A >> B >> C >> D;
		seq[0][i] = A;
		seq[1][i] = B;
		seq[2][i] = C;
		seq[3][i] = D;
	}

	std::vector<ll> left;
	std::vector<ll> right;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			left.push_back(seq[0][i] + seq[1][j]);
			right.push_back(seq[2][i] + seq[3][j]);
		}
	}

	std::sort(right.begin(), right.end());

	ll ans = 0;
	for(const auto& itr : left)
	{
		ll target = -itr;
		
		ll l = 0;
		ll r = right.size();

		// lower bound
		ll lowerBound = 0;
		while (l < r)
		{
			ll m = (l + r) / 2;
			if (target <= right[m])
			{
				r = m;
			}
			else
			{
				l = m + 1;
			}
		}
		lowerBound = l;


		l = 0;
		r = right.size();

		// upper bound
		ll upperBound = 0;
		while (l < r)
		{
			ll m = (l + r) / 2;
			if (target < right[m])
			{
				r = m;
			}
			else
			{
				l = m + 1;
			}
		}
		upperBound = l;

		ans += upperBound - lowerBound;
	}

	std::cout << ans;

	return 0;
}