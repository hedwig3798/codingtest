#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> liquid(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> liquid[i];
	}

	sort(liquid.begin(), liquid.end());

	vector<long long> ans;
	long long min = 3e9;

	for (int i = 0; i < N - 2; i++)
	{
		long long target = liquid[i];


		int start = i + 1;
		int end = N - 1;

		while (start < end)
		{
			long long now = liquid[start] + liquid[end] + target;
			if (std::abs(now) < min)
			{
				ans = vector<long long>{ liquid[start], liquid[end], target };
				min = std::abs(now);
			}

			if (now < 0)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		
	}

	sort(ans.begin(), ans.end());
	
	for(auto& a : ans) 
	{
		cout << a << " ";
	}

	return 0;
}