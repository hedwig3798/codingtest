#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<long long> trees(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
	}

	int start = 0;
	int end = *max_element(trees.begin(), trees.end());
	long long  result = 0;

	while (start <= end)
	{
		long long now = 0;
		int mid = (start + end) / 2;
		for (auto& t : trees)
		{
			if (t > mid)
			{
				now += t - mid;
			}
		}
		if (now < M)
		{
			end = mid - 1;
		}
		else
		{
			result = mid;
			start = mid + 1;
		}
	}

	cout << result;

	return 0;
}