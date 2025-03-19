#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N;
int worngTaps[1000] = { 0, };
int correctTaps[1000] = { 0, };
int offsetTaps[1000] = { 0, };

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> worngTaps[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> correctTaps[i];
		offsetTaps[i] = correctTaps[i] - worngTaps[i];
	}

	int start = 0;
	int ans = 0;

	while (start < N)
	{
		if (offsetTaps[start] == 0)
		{
			start++;
			continue;
		}

		if (offsetTaps[start] > 0)
		{
			int less = offsetTaps[start];
			int ind = start;
			while (ind < N)
			{
				if (offsetTaps[ind] <= 0)
				{
					break;
				}

				less = min(less, offsetTaps[ind]);
				++ind;
			}
			ans += less;

			for (int i = start; i < ind; i++)
			{
				offsetTaps[i] -= less;
			}
		}
		else if(offsetTaps[start] < 0)
		{
			int less = offsetTaps[start];
			int ind = start;
			while (ind < N)
			{
				if (offsetTaps[ind] >= 0)
				{
					break;
				}

				less = max(less, offsetTaps[ind]);
				++ind;
			}

			ans += -less;

			for (int i = start; i < ind; i++)
			{
				offsetTaps[i] -= less;
			}
		}
	}

	cout << ans;

	return 0;
}