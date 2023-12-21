#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <memory.h>

#define INF (int)1e9
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
ll N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	vector<ll> mul(N, 0);
	vector<ll> scobil(N, 0);

	for (ll i = 1; i < N; i++)
	{
		mul[i] = (((mul[i - 1]) + 1) * 2 - 1) % MOD;
	}

	for (ll i = 0; i < N; i++)
	{
		cin >> scobil[i];
	}

	sort(scobil.begin(), scobil.end());

	ll high = 0;
	ll low = 0;

	for (ll i = N - 1; i > 0; i--)
	{
		high += mul[i] * scobil[i];
		high %= MOD;
		low += mul[i] * scobil[N - 1 - i];
		low %= MOD;
	}

	ll ans = (high - low + MOD) % MOD;
	cout << ans;
	return 0;
}