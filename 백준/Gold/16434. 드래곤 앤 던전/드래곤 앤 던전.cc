#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	ll curHP = 0;
	ll atk;
	ll ans = 0;

	std::cin >> N >> atk;

	for (int i = 0; i < N; i++)
	{
		ll t, a, h;
		std::cin >> t >> a >> h;

		switch (t)
		{
		case 1:
			h -= atk;
			if (0 < h)
			{
				if (0 == h % atk)
				{
					curHP += a * h / atk;
				}
				else
				{
					curHP += a * (h / atk + 1);
				}
			}
			break;
		case 2:
			curHP = std::max(curHP - h, 0LL);
			atk += a;
			break;
		default:
			break;
		}
		ans = std::max(ans, curHP);
	}

	std::cout << ans + 1;
	return 0;
}