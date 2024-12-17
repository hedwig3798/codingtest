#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;

ll N, M, K;
vector<ll> sTree;
vector<ll> seq;
vector<ll> lazy;

ll h;
ll treeSize;


void InitTree(ll _node, ll _start, ll _end)
{
	if (_start == _end) 
	{
		sTree[_node] = seq[_start];
	}
	else 
	{
		ll mid = (_start + _end) * 0.5;

		InitTree(_node << 1, _start, mid);
		InitTree(_node << 1 | 1, mid + 1, _end);
		sTree[_node] = sTree[_node << 1] + sTree[_node << 1 | 1];
	}
}

void LazyUpdate(ll _node, ll _start, ll _end)
{
	if (lazy[_node] != 0)
	{
		sTree[_node] += lazy[_node] * (_end - _start + 1);
		if (_start != _end)
		{
			lazy[_node << 1] += lazy[_node];
			lazy[_node << 1 | 1] += lazy[_node];
		}
		lazy[_node] = 0;
	}
}

ll Query(ll _node, ll _start, ll _end, ll _left, ll _right)
{
	LazyUpdate(_node, _start, _end);

	if (_left > _end || _right < _start)
	{
		return 0;
	}

	if (_left <= _start && _right >= _end)
	{
		return sTree[_node];
	}

	ll mid = (_start + _end) * 0.5;

	return Query(_node << 1, _start, mid, _left, _right) + Query(_node << 1 | 1, mid + 1, _end, _left, _right);
}

void RangeUpdate(ll _node, ll _start, ll _end, ll _left, ll _right, ll _diff)
{
	LazyUpdate(_node, _start, _end);

	if (_left > _end || _right < _start)
	{
		return;
	}

	if (_left <= _start && _right >= _end)
	{
		sTree[_node] += (_end - _start + 1) * _diff;
		if (_start != _end)
		{
			lazy[_node << 1] += _diff;
			lazy[_node << 1 | 1] += _diff;
		}
		return;
	}

	ll mid = (_start + _end) * 0.5;

	RangeUpdate(_node << 1, _start, mid, _left, _right, _diff);
	RangeUpdate(_node << 1 | 1, mid + 1, _end, _left, _right, _diff);

	sTree[_node] = sTree[_node << 1] + sTree[_node << 1 | 1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	h = (ll)ceil(log2(N));
	treeSize = (1 << (h + 1));

	sTree = vector<ll>(treeSize, 0);
	lazy = vector<ll>(treeSize, 0);
	seq = vector<ll>(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}

	InitTree(1, 0, N - 1);

	for (int i = 0; i < K + M; i++)
	{
		ll q;
		cin >> q;

		switch (q)
		{
		case 1:
		{
			ll left, right, diff;
			cin >> left >> right >> diff;
			RangeUpdate(1, 0, N - 1, left - 1, right - 1, diff);
			break;
		}
		case 2:
		{
			ll left, right;
			cin >> left >> right;

			cout << Query(1, 0, N - 1, left - 1, right - 1) << "\n";
			break;
		}
		default:
			break;
		}
	}

	return 0;
}