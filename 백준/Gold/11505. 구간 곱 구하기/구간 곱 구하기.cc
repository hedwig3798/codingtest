#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MOD 1'000'000'007
#define MAX_N 1'000'000

int N, M, K;
long long sTree[MAX_N * 2];


void InitTree()
{
	for (int i = N - 1; i > 0; --i)
	{
		sTree[i] = (sTree[i << 1] * sTree[(i << 1) | 1]) % MOD;
	}
}

void Update(int _pos, long long _val)
{
	int nPos = _pos + N;
	sTree[nPos] = _val;

	while (nPos > 1)
	{
		sTree[nPos >> 1] = (sTree[nPos] * sTree[nPos ^ 1]) % MOD;
		nPos >>= 1;
	}
}

long long Query(int _left, int _right)
{
	long long res = 1;

	for (_left += N, _right += N; _left < _right; _left >>= 1, _right >>= 1)
	{
		if (1 == (_left & 1))
		{
			res = (res * sTree[_left]) % MOD;
			_left += 1;
		}

		if (1 == (_right & 1))
		{
			_right -= 1;
			res = (res * sTree[_right]) % MOD;
		}
	}

	return res;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> sTree[i + N];
	}

	InitTree();

	for (int i = 0; i < K + M; ++i)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		switch (a)
		{
		case 1:
		{
			Update(b - 1, c);
			break;
		}
		case 2:
		{
			std::cout << Query(b - 1, c) << '\n';
			break;
		}
		default:
			break;
		}
	}

	return 0;
}