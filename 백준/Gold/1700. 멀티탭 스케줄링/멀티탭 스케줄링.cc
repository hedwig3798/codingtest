#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, K;
int seq[101] = { 0, };
bool plug[101] = { 0, };
std::set<int> multitep;
int ans = 0;

int RemoveMultitep(int _start)
{
	int lastIndex = 0;
	for(const auto& m : multitep)
	{
		int index = -1;
		for (int i = _start; i <= K ; i++)
		{
			if (m == seq[i])
			{
				index = i;
				break;
			}
		}

		if (-1 == index)
		{
			return m;
		}
		else
		{
			lastIndex = std::max(lastIndex, index);
		}
	}

	return seq[lastIndex];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> K;

	if (N >= K)
	{
		std::cout << 0;
		return 0;
	}

	for (int i = 0; i < K; i++)
	{
		std::cin >> seq[i];
	}

	for (int i = 0; i < K; i++)
	{
		if (true == plug[seq[i]])
		{
			continue;
		}

		if (multitep.size() < N)
		{
			multitep.insert(seq[i]);
			plug[seq[i]] = true;
			continue;
		}

		ans++;
		int action = RemoveMultitep(i);

		multitep.erase(action);
		plug[action] = false;

		multitep.insert(seq[i]);
		plug[seq[i]] = true;
	}

	std::cout << ans;

	return 0;
}