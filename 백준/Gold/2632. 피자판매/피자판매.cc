#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N;
int ca, cb;
int A[1001] = { 0, };
int B[1001] = { 0, };

int sumA[1001][1001] = { 0, };
int sumB[1001][1001] = { 0, };

std::map<int, int> mapP;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	std::cin >> ca >> cb;

	for (int i = 0; i < ca; i++)
	{
		std::cin >> A[i];
	}

	for (int i = 0; i < cb; i++)
	{
		std::cin >> B[i];
	}

	for (int i = 0; i < ca; i++)
	{
		for (int j = 0; j < ca; j++)
		{
			int next = (i + j) % ca;
			sumA[i][next] = sumA[i][(next - 1 + ca) % ca] + A[next];
		}
	}

	for (int i = 0; i < cb; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			int next = (i + j) % cb;
			sumB[i][next] = sumB[i][(next - 1 + cb) % cb] + B[next];
		}
	}

	ll ans = 0;
	std::map<int, int> m;

	m[0] = 1;
	m[sumB[0][cb - 1]] += 1;

	for (int i = 0; i < cb; i++)
	{
		for (int j = 0; j < cb - 1; j++)
		{
			int next = (i + j) % cb;
			m[sumB[i][next]]++;
		}
	}

	for (int i = 0; i < ca; i++)
	{
		for (int j = 0; j < ca - 1; j++)
		{
			int next = (i + j) % ca;
			ans += m[N - sumA[i][next]];
		}
	}

	ans += m[N];
	ans += m[N - sumA[0][ca - 1]];

	std::cout << ans;

	return 0;
}