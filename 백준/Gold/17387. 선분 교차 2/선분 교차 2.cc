#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>

#define INF 1e9
using namespace std;

struct Line
{
	long long x1, y1, x2, y2;
};

long long IsCCW(pair<long long, long long> _a, pair<long long, long long> _b, pair<long long, long long> _c)
{
	long long result = _a.first * _b.second + _b.first * _c.second + _c.first * _a.second;
	result -= _a.second * _b.first + _b.second * _c.first + _c.second * _a.first;
	if (result < 0)
	{
		return -1;
	}
	else if (result == 0)
	{
		return 0;
	}
	else if (result > 0)
	{
		return 1;
	}
}

bool IsCross(Line _ab, Line _cd)
{
	pair<long long, long long> a = { _ab.x1, _ab.y1 };
	pair<long long, long long> b = { _ab.x2, _ab.y2 };
	pair<long long, long long> c = { _cd.x1, _cd.y1 };
	pair<long long, long long> d = { _cd.x2, _cd.y2 };

	long long ab = IsCCW(a, b, c) * IsCCW(a, b, d);
	long long cd = IsCCW(c, d, a) * IsCCW(c, d, b);

	if (ab == 0 && cd == 0)
	{
		if (a > b)
		{
			swap(a, b);
		}
		if (c > d)
		{
			swap(c, d);
		}
		return a <= d && c <= b;
	}
	return ab <= 0 && cd <= 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Line a, b;

	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	cout << (int)IsCross(a, b);

	return 0;
}