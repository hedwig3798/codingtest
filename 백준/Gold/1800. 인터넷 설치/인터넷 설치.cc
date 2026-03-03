#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

constexpr int MAX_N = 1'001;
constexpr int MAX_P = 10'001;
constexpr int MAX_C = 1'000'001;

int N, P, K;
std::vector<std::pair<int, int>> computers[MAX_N];

bool DIK(int _target)
{
	bool isVisit[MAX_N] = { 0, };

	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (false == pq.empty())
	{
		auto curr = pq.top();
		int cCost = -curr.first;
		int cNode = curr.second;
		pq.pop();

		if (true == isVisit[cNode])
		{
			continue;
		}
		isVisit[cNode] = true;


		if (cNode == N)
		{
			return cCost <= K;
		}

		for(const auto& next : computers[cNode])
		{
			int nNode = next.first;
			int nCost = cCost;
			if (next.second > _target)
			{
				nCost++;
			}


			if (false == isVisit[nNode])
			{
				pq.push({ -nCost, nNode });
			}
		}
	}

	return false;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> P >> K;

	for (int i = 0; i < P; ++i)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		computers[a].push_back({ b, c });
		computers[b].push_back({ a, c });
	}

	int left = 0;
	int right = MAX_C;

	int ans = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (false == DIK(mid))
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	std::cout << ans;

	return 0;
}