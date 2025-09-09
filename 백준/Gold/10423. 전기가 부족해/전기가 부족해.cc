#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, M, K;


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M >> K;

	std::vector<std::vector<pii>> city(N + 1);
	std::vector<int> elecity;
	for (int i = 0; i < K; i++)
	{
		int k;
		std::cin >> k;
		elecity.push_back(k);
	}

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;

		city[u].push_back({ v, w });
		city[v].push_back({ u, w });
	}



	std::priority_queue<pii> pq;
	std::vector<bool> isVisit(N + 1, false);

	for (const auto& u : elecity)
	{
		isVisit[u] = true;
		for(const auto& vw : city[u])
		{
			pq.push({ -vw.second, vw.first });
		}
	}

	int ans = 0;
	while (false == pq.empty())
	{
		const auto& curr = pq.top();
		int cCost = -curr.first;
		int cNode = curr.second;
		pq.pop();
		
		if (false == isVisit[cNode])
		{
			ans += cCost;
			isVisit[cNode] = true;
		}
		else
		{
			continue;
		}

		for(const auto& vw : city[cNode])
		{
			int nNode = vw.first;
			int nCost = vw.second;

			if (false == isVisit[nNode])
			{
				pq.push({-nCost, nNode});
			}
		}
	}

	std::cout << ans;

	return 0;
}