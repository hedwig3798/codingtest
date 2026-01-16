#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 100'000

std::pair<int, int> points[MAX_COUNT];
int n;

int Distance(std::pair<int, int>& _a, std::pair<int, int>& _b)
{
	int x = _a.first - _b.first;
	int y = _a.second - _b.second;

	return (x * x) + (y * y);
}

int Shortest(int _left, int _right)
{
	int range = _right - _left + 1;
	if (2 == range)
	{
		return Distance(points[_left], points[_right]);
	}
	if (3 == range)
	{
		int result = std::min(Distance(points[_left], points[_left + 1]), Distance(points[_left], points[_left + 2]));
		return std::min(result, Distance(points[_left + 2], points[_left + 1]));
	}

	int mid = (_left + _right) / 2;

	int result = std::min(Shortest(_left, mid), Shortest(mid + 1, _right));

	int center = (points[mid].first + points[mid + 1].first) / 2;
	std::vector<std::pair<int, int>> candiate;
	for (int i = _left; i <= _right; i++)
	{
		int xRange = center - points[i].first;
		xRange *= xRange;
		if (xRange < result)
		{
			candiate.push_back(points[i]);
			std::swap(candiate.back().first, candiate.back().second);
		}
	}
	std::sort(candiate.begin(), candiate.end());
	for (int i = 0; i < candiate.size(); i++)
	{
		for (int j = i + 1; j < candiate.size(); j++)
		{
			int yRange = candiate[i].first - candiate[j].first;
			yRange *= yRange;
			if (yRange < result)
			{
				result = std::min(result, Distance(candiate[i], candiate[j]));
			}
			else
			{
				break;
			}
		}
	}

	return result;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> points[i].first >> points[i].second;
	}

	std::sort(points, points + n);


	std::cout << Shortest(0, n - 1);

	return 0;
}