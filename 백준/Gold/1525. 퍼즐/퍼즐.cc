#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::string s;
	std::string target = "123456780";
	for (int i = 0; i < 9; i++)
	{
		char c;
		std::cin >> c;
		s.push_back(c);
	}

	std::set<std::string> isVisit;
	isVisit.insert(s);

	std::queue<std::pair<std::string, int>> q;
	q.push({ s, 0 });
	while (false == q.empty())
	{
		auto& curr = q.front();
		std::string cs = curr.first;
		int ci = curr.second;
		q.pop();

		if (cs == target)
		{
			std::cout << ci;
			return 0;
		}

		int cpos = cs.find('0');
		int cx = cpos / 3;
		int cy = cpos % 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0
				|| nx >= 3
				|| ny < 0
				|| ny >= 3)
			{
				continue;
			}

			std::string ns = cs;
			std::swap(ns[cx * 3 + cy], ns[nx * 3 + ny]);

			auto sit = isVisit.find(ns);
			if (sit != isVisit.end())
			{
				continue;
			}

			isVisit.insert(ns);
			q.push({ ns, ci + 1 });
		}
	}

	std::cout << -1;

	return 0;
}