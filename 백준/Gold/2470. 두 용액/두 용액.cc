#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<long long>value(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}

	sort(value.begin(), value.end());

	int minv = 0;
	int maxv = n - 1;

	long long old = 2'000'000'001;
	pair<int, int> ans = { minv, maxv };

	while (true)
	{
		long long now = abs(value[minv] + value[maxv]);

		if (now < old)
		{
			ans = { minv , maxv };
			old = now;
		}

		if (value[minv] + value[maxv] > 0)
		{
			maxv--;
		}
		else if (value[minv] + value[maxv] < 0)
		{
			minv++;
		}
		else
		{
			cout << value[minv] << " " << value[maxv];
			return 0;
		}

		if (minv == maxv)
		{
			break;
		}
	}

	cout << value[ans.first] << " " << value[ans.second];

	return 0;
}