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

	std::cin >> N;

	std::vector<pii> meetings;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		std::cin >> start >> end;
		meetings.push_back({ start, end });
	}

	std::sort(meetings.begin(), meetings.end());

	std::priority_queue<int> pq;
	pq.push(-meetings[0].second);

	int ans = 1;

	for (int i = 1; i < N; i++)
	{
		int start = meetings[i].first;
		int end = meetings[i].second;

		while (false == pq.empty()
			&& -pq.top() <= start)
		{
			pq.pop();
		}

		pq.push(-end);
		ans = std::max(ans, (int)pq.size());
	}

	std::cout << ans;

	return 0;
}