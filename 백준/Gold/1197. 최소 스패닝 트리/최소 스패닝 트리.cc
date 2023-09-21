#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

struct Node
{
	int start;
	int end;
	int cost;
};

bool cmp(Node _a, Node _b)
{
	return _a.cost < _b.cost;
}

int FindParent(int _target, vector<int>& _uf)
{
	int origin = _target;
	while (_uf[_target] != _target)
	{
		_target = _uf[_target];
	}
	return _uf[origin] = _target;
}

bool IsSameUnion(int _a, int _b, vector<int>& uf)
{
	return FindParent(_a, uf) == FindParent(_b, uf);
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
	int V, E;
	cin >> V >> E;

	vector<Node> graph;

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		graph.push_back(Node{ A, B, C });
	}

	sort(graph.begin(), graph.end(), cmp);

	vector<int> uf(V + 1);
	for (int i = 0; i < V; i++)
	{
		uf[i + 1] = i + 1;
	}

	int result = graph[0].cost;
	makeUnion(graph[0].start, graph[0].end, uf);
	
	for (int i = 1; i < graph.size(); i++)
	{
		if (IsSameUnion(graph[i].start, graph[i].end, uf))
		{
			continue;
		}
		else
		{
			makeUnion(graph[i].start, graph[i].end, uf);
			result += graph[i].cost;
		}
	}

	cout << result;
}