#include <bits/stdc++.h>

#define le9 1'000'000'001
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N, M;

vector<ll> numbers;
vector<ll> sTree;

void InitTree()
{
	for (ll i = N - 1; i > 0; i--)
	{
		sTree[i] = min(sTree[i << 1], sTree[i << 1 | 1]);
	}
}

int Query(ll _left, ll _right)
{
	ll result = le9;

	for (_left += N, _right += N; _left < _right; _left >>= 1, _right >>= 1)
	{
		if (_left & 1)
		{
			result = min(result, sTree[_left++]);
		}
		if (_right & 1)
		{
			result = min(result, sTree[--_right]);
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	sTree = vector<ll>(2 * N);

	for (ll i = 0; i < N; i++)
	{
		cin >> sTree[i + N];
	}

	InitTree();

	for (ll i = 0; i < M; i++)
	{
		ll s, e;
		cin >> s >> e;
		cout << Query(s - 1, e) << "\n";
	}



	return 0;
}