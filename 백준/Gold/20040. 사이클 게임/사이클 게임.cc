#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int FindParent(int _target, vector<int>& _uf)
{
	if (_uf[_target] == _target)
	{
		return _target;
	}
	else
	{
		_uf[_target] = FindParent(_uf[_target], _uf);
		return _uf[_target];
	}
}

void makeUnion(int _child, int _parent, vector<int>& uf)
{
	_child = FindParent(_child, uf);
	_parent = FindParent(_parent, uf);
	uf[_child] = _parent;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> uf(n, 0);

	for (int i = 0; i < n; i++)
	{
		uf[i] = i;
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (FindParent(a, uf) == FindParent(b, uf)) 
		{
			cout << i + 1;
			return 0;
		}
		makeUnion(a, b, uf);
	}
	cout << 0;
	return 0;
}