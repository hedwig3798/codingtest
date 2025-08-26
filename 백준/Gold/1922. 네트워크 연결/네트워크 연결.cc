#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, M;
int uf[1001] = { 0, };

int GetParent(int _child)
{
	if (uf[_child] == _child)
	{
		return _child;
	}

	uf[_child] = GetParent(uf[_child]);
	return uf[_child];
}

void MergeUnion(int _a, int _b)
{
	int pa = GetParent(_a);
	int pb = GetParent(_b);

	uf[pa] = uf[pb];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		uf[i] = i;
	}


	std::priority_queue<std::vector<int>> pq;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		pq.push({ -c, a, b });
	}

	int ans = 0;
	while (false == pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		int cc = -curr[0];
		int ca = curr[1];
		int cb = curr[2];

		if (GetParent(ca) != GetParent(cb))
		{
			MergeUnion(ca, cb);
			ans += cc;
		}
	}

	std::cout << ans;

	return 0;
}