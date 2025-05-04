#include <bits/stdc++.h>
#include <unordered_set>
#define le9 1'000'000'001
#define MOD 1'000'003

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string L, R;
	cin >> L >> R;

	if (R.length() > L.length())
	{
		cout << 0;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < R.length(); i++)
	{
		if (R[i] == '8' && L[i] == '8')
		{
			ans++;
		}
		else if (R[i] != L[i])
		{
			break;
		}
	}

	cout << ans;

	return 0;
}