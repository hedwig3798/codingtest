#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int Find(vector<int>& _uf, int _target)
{
	if (_uf[_target] == _target)
	{
		return _target;
	}
	return _uf[_target] = Find(_uf, _uf[_target]);
}

void Union(vector<int>& _uf, int _a, int _b)
{
	int pa = Find(_uf, _a);
	int pb = Find(_uf, _b);

	_uf[pa] = pb;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<tuple<int, int, int>> town(M);
	vector<int> uf(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		town[i] = make_tuple(c, a, b);
	}

	for (int i = 0; i <= N; i++)
	{
		uf[i] = i;
	}

	sort(town.begin(), town.end());

	vector<tuple<int, int, int>> MST;

	MST.push_back(town[0]);
	Union(uf, get<1>(town[0]), get<2>(town[0]));
	int result = get<0>(town[0]);

	for (int i = 1; i < M; i++)
	{
		int a = get<1>(town[i]);
		int b = get<2>(town[i]);

		if (Find(uf, a) == Find(uf, b)) 
		{
			continue;
		}
		else
		{
			MST.push_back(town[i]);
			result += get<0>(town[i]);
			Union(uf, a, b);
			if (MST.size() == N - 1) 
			{
				break;
			}
		}
	}

	sort(MST.begin(), MST.end());

	result -= get<0>(MST.back());

	cout << result;

	return 0;
}