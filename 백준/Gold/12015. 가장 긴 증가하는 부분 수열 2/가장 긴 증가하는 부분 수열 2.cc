#include <iostream>
#include <vector>
#include <algorithm>

int seq[1000001] = { 0, };

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (ans.size() == 0 || ans.back() < seq[i])
		{
			ans.push_back(seq[i]);
			continue;
		}
		else
		{
			int start = 0;
			int end = ans.size() - 1;

			while (start < end)
			{
				int mid = (start + end) / 2;

				if (ans[mid] < seq[i])
				{
					start = mid + 1;
				}
				else
				{
					end = mid;
				}
			}
			ans[start] = seq[i];
		}
	}

	cout << ans.size();

	return 0;
}
