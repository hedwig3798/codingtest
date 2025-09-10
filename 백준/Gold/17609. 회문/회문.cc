#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int IsPen(std::string& _s, int _left, int _right, int _wrong)
{
	if (_left >= _right)
	{
		return _wrong;
	}

	if (_s[_left] == _s[_right])
	{
		return IsPen(_s, _left + 1, _right - 1, _wrong);
	}

	_wrong++;
	if (_wrong >= 2)
	{
		return 2;
	}

	int left = IsPen(_s, _left + 1, _right, _wrong);
	int right = IsPen(_s, _left, _right - 1, _wrong);

	return std::min(left, right);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int T;
	std::cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		std::string s;
		std::cin >> s;

		std::cout << IsPen(s, 0, s.size() - 1, 0) << "\n";
	}

	return 0;
}