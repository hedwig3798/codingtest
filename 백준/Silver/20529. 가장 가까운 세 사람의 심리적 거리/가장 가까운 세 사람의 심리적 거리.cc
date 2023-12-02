#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

vector<string> mdti;

int Distance(const string& _a, const string& _b)
{
	int result = 0;
	for (int i = 0; i < _a.length(); i++)
	{
		if (_a[i] != _b[i])
		{
			result++;
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int N;
		cin >> N;
		mdti = vector<string>(N);
		for (int i = 0; i < N; i++)
		{
			cin >> mdti[i];
		}

		if (N >= 33)
		{
			cout << "0\n";
			continue;
		}


		int result = INF;

		for (int i = 0; i < N - 2; i++)
		{
			for (int j = i + 1; j < N - 1; j++)
			{
				for (int k = j + 1; k < N; k++)
				{
					int dis = Distance(mdti[i], mdti[j]);
					dis += Distance(mdti[i], mdti[k]);
					dis += Distance(mdti[j], mdti[k]);
					result = min(dis, result);
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}