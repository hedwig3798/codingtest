#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

struct Line
{
	int x1, y1, x2, y2;
};

int IsCCW(pair<int, int> _a, pair<int, int> _b, pair<int, int> _c)
{
	int result = _a.first * _b.second + _b.first * _c.second + _c.first * _a.second;
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
	pair<int, int> a = { _ab.x1, _ab.y1 };
	pair<int, int> b = { _ab.x2, _ab.y2 };
	pair<int, int> c = { _cd.x1, _cd.y1 };
	pair<int, int> d = { _cd.x2, _cd.y2 };

	int ab = IsCCW(a, b, c) * IsCCW(a, b, d);
	int cd = IsCCW(c, d, a) * IsCCW(c, d, b);

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


int FindParent(int _target, vector<pair<int, int>>& _uf)
{
	int origin = _target;
	while (_uf[_target].first != _target)
	{
		_target = _uf[_target].first;
	}
	return _uf[origin].first = _target;
}

bool IsSameUnion(int _a, int _b, vector<pair<int, int>>& uf)
{
	return FindParent(_a, uf) == FindParent(_b, uf);
}

void makeUnion(int _child, int _parent, vector<pair<int, int>>& uf)
{
	_child = FindParent(_child, uf);
	_parent = FindParent(_parent, uf);
	uf[_child].first = _parent;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> unionFind(N);
	vector<Line> lineList(N);

	for (int i = 0; i < N; i++)
	{
		unionFind[i] = { i, 0 };
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;
		Line line = { x1, y1, x2, y2 };
		lineList[i] = line;

		for (int j = 0; j < i; j++)
		{
			if (IsCross(lineList[j], line))
			{
				makeUnion(i, j, unionFind);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		unionFind[FindParent(i, unionFind)].second++;
	}

	int groupCount = 0;
	int lineCount = 0;

	for (int i = 0; i < N; i++)
	{
		if (unionFind[i].first == i)
		{
			groupCount++;
			if (unionFind[i].second > lineCount)
			{
				lineCount = unionFind[i].second;
			}
		}
	}

	cout << groupCount << "\n" << lineCount;

	return 0;
}