#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define Point std::pair<double, double>
#define MAX_NUM 100

int n;
Point start, end;

double dp[MAX_NUM][MAX_NUM] = { 0, };
Point cannons[MAX_NUM + 2] = {};
bool isVisit[MAX_NUM] = { 0, };


double GetDistance(Point& _a, Point& _b)
{
	double x = _a.first - _b.first;
	double y = _a.second - _b.second;

	return sqrt(x * x + y * y);
}

double GetTime(Point& _a, Point& _b)
{
	double dis = GetDistance(_a, _b);
	double run = dis / 5.0;
	double useCannon = 2.0 + fabs(dis - 50.0) / 5.0;

	return std::min(run, useCannon);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> start.first >> start.second;
	std::cin >> end.first >> end.second;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> cannons[i].first >> cannons[i].second;
	}

	std::priority_queue<std::pair<double, int>> pq;

	double ans = GetDistance(start, end) / 5.0;
	for (int i = 0; i < n; i++)
	{
		double dis = GetDistance(start, cannons[i]);
		pq.push({ (-dis / 5), i });
	}

	while (false == pq.empty())
	{
		auto curr = pq.top();
		double cTime = -curr.first;
		int cNode = curr.second;
		pq.pop();

		isVisit[cNode] = true;
		ans = std::min(ans, cTime + (GetTime(cannons[cNode], end)));

		for (int i = 0; i < n; i++)
		{
			if (true == isVisit[i])
			{
				continue;
			}

			double nTime = cTime + GetTime(cannons[cNode], cannons[i]);
			pq.push({ -nTime, i });
		}
	}

	std::cout << ans;

	return 0;
}