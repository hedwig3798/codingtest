#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int FindParent(vector<int>& _uf, int _target)
{
	if (_uf[_target] == _target)
	{
		return _target;
	}
	_uf[_target] = FindParent(_uf, _uf[_target]);
	return _uf[_target];
}

void Union(vector<int>& _uf, int _a, int _b)
{
	int pa = FindParent(_uf, _a);
	int pb = FindParent(_uf, _b);

	_uf[pa] = pb;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> position[3];
	vector<tuple<long long, int, int>> cost;

	vector<int> uf(N, 0);

	for (int i = 0; i < N; i++)
	{
		long long x, y, z;
		cin >> x >> y >> z;

		position[0].push_back({ x, i });
		position[1].push_back({ y, i });
		position[2].push_back({ z, i });
		uf[i] = i;
	}

	sort(position[0].begin(), position[0].end());
	sort(position[1].begin(), position[1].end());
	sort(position[2].begin(), position[2].end());

	for (int i = 0; i < N - 1; i++)
	{
		cost.push_back(make_tuple(abs(position[0][i].first - position[0][i + 1].first), position[0][i].second, position[0][i + 1].second));
		cost.push_back(make_tuple(abs(position[1][i].first - position[1][i + 1].first), position[1][i].second, position[1][i + 1].second));
		cost.push_back(make_tuple(abs(position[2][i].first - position[2][i + 1].first), position[2][i].second, position[2][i + 1].second));
	}

	sort(cost.begin(), cost.end());

	long long result = 0;

	for (size_t i = 0; i < cost.size(); i++)
	{
		if (FindParent(uf, get<1>(cost[i])) == FindParent(uf, get<2>(cost[i])))
		{
			continue;
		}
		result += get<0>(cost[i]);
		Union(uf, get<1>(cost[i]), get<2>(cost[i]));
	}

	cout << result;

	return 0;
}