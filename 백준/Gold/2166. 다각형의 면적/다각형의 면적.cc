#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

double Area(pair<long double, long double> _a, pair<long double, long double> _b, pair<long double, long double> _c)
{
	long double result = _a.first * _b.second + _b.first * _c.second + _c.first * _a.second;
	result -= _a.second * _b.first + _b.second * _c.first + _c.second * _a.first;

	return  result / 2;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<long double, long double>> vertexes;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		vertexes.push_back({ x,y });
	}

	long double result = 0;

	for (size_t i = 1; i < vertexes.size() - 1; i++)
	{
		result += Area(vertexes[0], vertexes[i], vertexes[i + 1]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(result);

	return 0;
}