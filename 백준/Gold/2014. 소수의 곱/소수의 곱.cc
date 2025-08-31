#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int K, N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> K >> N;
	std::vector<ll> prime(K);
	std::priority_queue<ll> pq;
	for (int i = 0; i < K; i++)
	{
		std::cin >> prime[i];
		pq.push(-prime[i]);
	}

	ll ans = 0;
	ll temp = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			ans = -pq.top();

			temp = ans * prime[j];
			if (temp >= INT_MAX)
			{
				break;
			}

			pq.push(-temp);

			if (0 == ans % prime[j])
			{
				break;
			}
		}
		pq.pop();
	}

	std::cout << ans;

	return 0;
}