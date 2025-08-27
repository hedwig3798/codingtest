#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;
std::vector<pii> loger;

ll Hanoi(int _now, int _start, int _dest, int _temp)
{
	if (1 == _now)
	{
		if (20 >= N)
		{
			loger.push_back({ _start, _dest });
		}
		return 1;
	}

	ll count = 0;

	count += Hanoi(_now - 1, _start, _temp, _dest);

	count++;
	if (20 >= N)
	{
		loger.push_back({ _start, _dest });
	}

	count += Hanoi(_now - 1, _temp, _dest, _start);

	return count;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	std::cin >> N;

	if (20 >= N)
	{
		std::cout << Hanoi(N, 1, 3, 2) << '\n';

		for (const auto& itr : loger)
		{
			std::cout << itr.first << ' ' << itr.second << '\n';
		}
	}
	else
	{
		std::string result = std::to_string(pow(2, N));
		int index = result.find('.'); 
		result = result.substr(0, index);
		result[result.length() - 1] -= 1;

		std::cout << result;
	}

	return 0;
}