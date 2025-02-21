#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


int N;
vector<ll> U;
vector<ll> sum2;

bool BS(ll _target)
{
	int s = 0;
	int e = sum2.size() - 1;
	

	while (s < e)
	{
		int m = (s + e) / 2;

		if (sum2[m] == _target)
		{
			return true;
		}

		if (sum2[m] > _target)
		{
			e = m;
		}
		else
		{
			s = m + 1;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	U.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> U[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			sum2.push_back(U[i] + U[j]);
		}
	}

	sort(U.begin(), U.end());
	sort(sum2.begin(), sum2.end());

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			int ans = U[i] - U[j];
			if (BS(ans))
			{
				cout << U[i];
				return 0;
			}
		}
	}

	return 0;
}