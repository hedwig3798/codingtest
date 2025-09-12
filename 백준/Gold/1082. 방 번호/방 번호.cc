#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, M;
std::vector<int> P;

std::string ans;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	P.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> P[i];
	}
	std::cin >> M;

	pii iz = { 0, le9 };
	pii oz = { 0, le9 };

	for (int i = 0; i < N; i++)
	{
		if (P[i] < iz.second)
		{
			iz.first = i;
			iz.second = P[i];
		}
	}

	for (int i = 1; i < N; i++)
	{
		if (P[i] < oz.second)
		{
			oz.first = i;
			oz.second = P[i];
		}
	}

	if (M < oz.second)
	{
		std::cout << 0;
		return 0;
	}

	M -= oz.second;

	ans.push_back('0' + oz.first);
	while (M >= iz.second)
	{
		ans.push_back('0' + iz.first);
		M -= iz.second;
	}

	for (int i = 0; i < ans.length(); i++)
	{
		for (int j = 0; j < N; j++)
		{
			int ind = N - j - 1;
			int curr = ans[i] - '0';
			int need = P[ind] - P[curr];

			if (M >= need)
			{
				M -= need;
				ans[i] = ind + '0';
				break;
			}
		}
	}

	std::cout << ans;

	return 0;
}