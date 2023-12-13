#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <memory.h>

#define INF (int)1e9
using namespace std;

int N, M, K;
vector<int> cards;
vector<int> input;
vector<int> uf;

int FindParent(int _a)
{
	if (uf[_a] == _a)
	{
		return _a;
	}
	else
	{
		uf[_a] = FindParent(uf[_a]);
		return uf[_a];
	}
}

void Union(int _child , int _parent)
{
	uf[FindParent(_child)] = FindParent(_parent);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	cards.resize(M);
	for (int i = 0; i < M; i++)
	{
		cin >> cards[i];
	}
	uf.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		uf[i] = i;
	}

	sort(cards.begin(), cards.end());

	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;

		auto ub = upper_bound(cards.begin(), cards.end(), num);
		int ans = FindParent(*ub);
		
		cout << ans << "\n";

		if (ans == cards.back())
		{
			continue;
		}

		ub = upper_bound(cards.begin(), cards.end(), ans);
		Union(*(ub - 1), *ub);
	}

	return 0;
}