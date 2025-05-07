#include <bits/stdc++.h>
#include <unordered_set>
#define le9 1'000'000'001
#define MOD 1'000'003

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;


vector<pair<pll, int>> busmap;

ll N, M;


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		ll a, b;
		cin >> a >> b;

		if (a < b)
		{
			busmap.push_back({ { a + N, b + N }, i });
			busmap.push_back({ { a, b }, i });
		}
		else
		{
			busmap.push_back({ { a, b + N }, i });
		}

	}

	sort(busmap.begin(), busmap.end(), [&](pair<pll, int> _a, pair<pll, int> _b)
		{
			if (_a.first.first == _b.first.first)
			{
				return _a.first.second > _b.first.second;
			}
			return _a.first.first < _b.first.first;
		});

	vector<bool> check(M, false);

	ll right = -1;
	for (auto& itr : busmap)
	{
		ll now = itr.first.second;
		if (now <= right)
		{
			check[itr.second] = true;
		}
		else
		{
			right = now;
		}
	}

	for (int i = 0; i < check.size(); i++)
	{
		if (!check[i])
		{
			cout << i + 1 << " ";
		}
	}

	return 0;
}