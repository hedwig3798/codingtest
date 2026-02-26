#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

using Point = std::pair<ll, ll>;

constexpr int MAX_N = 100'000;
int N;
Point points[MAX_N] = {};

int ans = 0;

// a -> b -> c 방향의 CW 여부
ll CheckCCW(Point _a, Point _b, Point _c)
{
	return (_b.first - _a.first) * (_c.second - _a.second) - (_b.second - _a.second) * (_c.first - _a.first);
}

ll Distance(Point a, Point b) 
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> points[i].first >> points[i].second;
	}

	std::sort(points, &points[N], [](const Point& _a, const Point& _b) -> bool
		{
			if (_a.second == _b.second)
			{
				return _a.first < _b.first;
			}
			else
			{
				return _a.second < _b.second;
			}
		}
	);

	std::stack<Point> s;

	std::sort(&points[1], &points[N], [](const Point& _a, const Point& _b) -> bool
		{
			ll ccw = CheckCCW(points[0], _a, _b);
			if (0 == ccw)
			{
				return Distance(points[0], _a) < Distance(points[0], _b);
			}
			else
			{
				return 0 < ccw;
			}
		}
	);

	s.push(points[0]);
	s.push(points[1]);

	for (int i = 2; i < N; ++i)
	{
		while (2 <= s.size())
		{
			Point p2 = s.top();
			s.pop();
			Point p1 = s.top();

			if (0 < CheckCCW(p1, p2, points[i]))
			{
				s.push(p2);
				break;
			}
		}

		s.push(points[i]);
	}

	std::cout << s.size();

	return 0;
}