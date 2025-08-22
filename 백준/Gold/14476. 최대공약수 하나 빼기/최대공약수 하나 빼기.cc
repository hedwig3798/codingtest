#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;

int Gcd(int _a, int _b)
{
	if (0 == _b)
	{
		return _a;
	}
	return Gcd(_b, _a % _b);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	std::vector<int> seq(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> seq[i];
	}

	std::vector<int> LTR(N);
	std::vector<int> RTL(N);

	LTR[0] = seq[0];
	RTL[N - 1] = seq[N - 1];

	for (int i = 1; i < N; i++)
	{
		LTR[i] = Gcd(LTR[i - 1], seq[i]);
	}
	for (int i = N - 2; i >= 0; i--)
	{
		RTL[i] = Gcd(RTL[i + 1], seq[i]);
	}

	int ans1 = -1;
	int ans2 = -1;

	for (int i = 0; i < N; i++)
	{
		int res = 0;
		if (0 == i)
		{
			res = RTL[1];
		}
		else if (N - 1 == i)
		{
			res = LTR[N - 2];
		}
		else
		{
			res = Gcd(LTR[i - 1], RTL[i + 1]);
		}


		if (seq[i] < res
			|| 0 != seq[i] % res)
		{
			if (ans1 < res)
			{
				ans1 = res;
				ans2 = seq[i];
			}
		}
	}

	if (-1 == ans1)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << ans1 << ' ' << ans2;
	}

	return 0;
}