#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_SCORE (1 << 20)

int n;

int segTree[MAX_SCORE * 2] = { 0, };

void Update(int _pos, int _val)
{
	segTree[_pos + MAX_SCORE] += _val;

	for (int i = _pos + MAX_SCORE; i > 1; i >>= 1)
	{
		segTree[i >> 1] = segTree[i] + segTree[i ^ 1];
	}
}

int Query(int _target)
{
	int res = 1;
	
	while (res < MAX_SCORE)
	{
		if (segTree[res << 1] >= _target)
		{
			res <<= 1;
		}
		else
		{
			_target -= segTree[res << 1];
			res = (res << 1) | 1;
		}
	}

	return res - MAX_SCORE;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int A;
		std::cin >> A;

		if (1 == A)
		{
			int B;
			std::cin >> B;

			int ans = Query(B);
			std::cout << ans << '\n';
			Update(ans, -1);
		}
		else if (2 == A)
		{
			int B, C;
			std::cin >> B >> C;
			Update(B, C);
		}
	}

	return 0;
}