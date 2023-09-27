#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> line;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		line.push_back({ a,b });
	}

	sort(line.begin(), line.end());

	vector<int> lis;
	vector<int> index;
	lis.push_back(line[0].second);
	index.push_back(0);

	for (int i = 1; i < N; i++)
	{
		if (lis.back() < line[i].second)
		{
			lis.push_back(line[i].second);
			index.push_back(lis.size() - 1);
		}
		else
		{
			int left = 0;
			int right = lis.size() - 1;
			while (left < right)
			{
				int mid = (right + left) / 2;
				if (lis[mid] < line[i].second)
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			lis[right] = line[i].second;
			index.push_back(right);
		}
	}


	cout << line.size() - lis.size() << "\n";

	int now = lis.size() - 1;
	vector<int> result;

	for (int i = index.size() - 1; i >= 0; i--)
	{
		if (now == index[i])
		{
			now--;
		}
		else
		{
			result.push_back(line[i].first);
		}
	}

	sort(result.begin(), result.end());

	for (auto r : result)
	{
		cout << r << "\n";
	}

	return 0;
}