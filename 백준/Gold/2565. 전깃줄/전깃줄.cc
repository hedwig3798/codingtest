#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

int bs(vector<int>& dp, int start, int end, int target)
{
	if (start > end) 
	{
		return -1;
	}
	int mid = (start + end) / 2;

	if (dp[mid] < target && target < dp[mid+1])
	{
		return mid + 1;
	}
	if (dp[mid] > target)
	{
		return bs(dp, start, mid - 1, target);
	}
	if (dp[mid] < target)
	{
		return bs(dp, mid + 1, end, target);
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> electric;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		electric.push_back({ a, b });
	}

	sort(electric.begin(), electric.end());

	vector<int> dp(N, 0);
	int dpsize = 1;
	for (int i = 0; i < N; i++)
	{
		int ind = bs(dp, 0, dpsize, electric[i].second);
		if (ind == -1) 
		{
			dp[dpsize] = electric[i].second;
			dpsize++;
		}
		else
		{
			dp[ind] = electric[i].second;
		}
	}

	cout << N - dpsize + 1;
}