#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::unordered_set<ll> s;

	int N;
	std::cin >> N;
	ll num = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> num;
		s.insert(num);
	}

	std::deque<ll> dq;
	s.erase(num);
	dq.push_back(num);

	while (false == s.empty())
	{
		ll left2 = 0, left3 = 0, right2 = 0, right3 = 0;
		if (1 == dq.size())
		{
			ll n = dq.front();

			if (0 == n % 2)
			{
				left2 = n / 2;

				auto sit = s.find(left2);
				if (sit != s.end())
				{
					dq.push_front(left2);
					s.erase(left2);
				}
			}

			{
				left3 = n * 3;
				auto sit = s.find(left3);
				if (sit != s.end())
				{
					dq.push_front(left3);
					s.erase(left3);
				}
			}

			{
				right2 = n * 2;
				auto sit = s.find(right2);
				if (sit != s.end())
				{
					dq.push_back(right2);
					s.erase(right2);
				}
			}
			if (0 == n % 3)
			{
				right3 = n / 3;
				auto sit = s.find(right3);
				if (sit != s.end())
				{
					dq.push_back(right3);
					s.erase(right3);
				}
			}
		}
		else
		{
			ll l = dq.front();
			ll r = dq.back();

			if (0 == l % 2)
			{
				left2 = l / 2;

				auto sit = s.find(left2);
				if (sit != s.end())
				{
					dq.push_front(left2);
					s.erase(left2);
				}
			}

			{
				left3 = l * 3;
				auto sit = s.find(left3);
				if (sit != s.end())
				{
					dq.push_front(left3);
					s.erase(left3);
				}
			}

			{
				right2 = r * 2;
				auto sit = s.find(right2);
				if (sit != s.end())
				{
					dq.push_back(right2);
					s.erase(right2);
				}
			}
			if (0 == r % 3)
			{
				right3 = r / 3;
				auto sit = s.find(right3);
				if (sit != s.end())
				{
					dq.push_back(right3);
					s.erase(right3);
				}
			}
		}
	}

	while (false == dq.empty())
	{
		std::cout << dq.front() << " ";
		dq.pop_front();
	}

	return 0;
}