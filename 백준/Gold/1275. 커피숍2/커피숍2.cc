#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_CONT 100'000

int N, Q;

ll segTree[MAX_CONT * 2];

void InitTree()
{
	for(int i = N - 1; i > 0; --i)
	{
		segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
	}
}

void Update(int _pos, ll _val)
{
	segTree[_pos + N] = _val;

	for (_pos += N; _pos > 1; _pos >>= 1)
	{
		segTree[_pos >> 1] = segTree[_pos] + segTree[_pos ^ 1];
	}
}

ll Query(int _left, int _right)
{
	ll res = 0;

	for (_left += N, _right += N; _left < _right; _left >>= 1, _right >>= 1)
	{
		if (1 == (_left & 1))
		{
			res += segTree[_left];
			++_left;
		}

		if (1 == (_right & 1))
		{
			--_right;
			res += segTree[_right];
		}
	}

	return res;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> Q;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> segTree[i + N];
	}

	InitTree();

	for (int i = 0; i < Q; ++i)
	{
		int x, y, a, b;
		std::cin >> x >> y >> a >> b;
		if (x > y)
		{
			std::swap(x, y);
		}

		std::cout << Query(x - 1, y) << '\n';
		Update(a - 1, b);
	}

	return 0;
}