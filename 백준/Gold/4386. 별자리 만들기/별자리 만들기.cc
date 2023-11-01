#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

float Distance(pair<double, double> _a, pair<double, double> _b)
{
	return sqrt(pow(_a.first - _b.first, 2.0) + pow(_a.second - _b.second, 2.0));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<double, double>> star(N, { 0.0f, 0.0f });
	vector<vector<pair<double, int>>> starGraph(N);

	for (int i = 0; i < N; i++)
	{
		cin >> star[i].first >> star[i].second;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			double distance = Distance(star[i], star[j]);
			starGraph[i].push_back({ -distance, j });
			starGraph[j].push_back({ -distance, i });
		}
	}

	double ans = 0.0f;
	priority_queue<pair<double, int>> pq;
	vector<bool> isVisit(N, false);
	isVisit[0] = true;

	for (int i = 0; i < N - 1; i++)
	{
		pq.push({ starGraph[0][i].first, starGraph[0][i].second });
	}

	while (!pq.empty())
	{
		auto nowDistance = pq.top().first;
		auto nowStar = pq.top().second;
		pq.pop();
		
		if (isVisit[nowStar])
		{
			continue;
		}

		ans += -nowDistance;
		isVisit[nowStar] = true;
		for(auto& s : starGraph[nowStar])
		{
			auto nextDistance = s.first;
			auto nextStar = s.second;
			if (isVisit[nextStar])
			{
				continue;
			}
			pq.push(s);
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << ans;

	return 0;
}