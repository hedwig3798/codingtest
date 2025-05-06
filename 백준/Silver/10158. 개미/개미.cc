#include <bits/stdc++.h>
#include <unordered_set>
#define le9 1'000'000'001
#define MOD 1'000'003

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int w, h, p, q, t;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> w >> h;
	cin >> p >> q;
	cin >> t;

	int x = (p + t) / w;
	int y = (q + t) / h;

	if (x % 2 == 0)
	{
		x = (p + t) % w;
	}
	else
	{
		x = w - (p + t) % w;
	}

	if (y % 2 == 0)
	{
		y = (q + t) % h;
	}
	else
	{
		y = h - (q + t) % h;
	}

	cout << x << " " << y;

	return 0;
}