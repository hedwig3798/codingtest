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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int G, P;
	cin >> G >> P;

	vector<int> uf(G + 1);
	for (int i = 0; i < G + 1; i++)
	{
		uf[i] = i;
	}

	int result = 0;
	for (int i = 0; i < P; i++)
	{
		int plane;
		cin >> plane;

		int parent = FindParent(plane, uf);
		if (parent == 0)
		{
			break;
		}

		result += 1;
		makeUnion(parent, parent - 1, uf);
	}

	cout << result;

	return 0;
}