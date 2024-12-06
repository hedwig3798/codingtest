#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;

int n;
vector<int> seq;
vector<int> ans;

int BS(int _find)
{
	int start = 0;
	int end = ans.size() - 1;


	while (start < end)
	{
		int mid = (end + start) / 2;

		if (_find > ans[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	seq = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (ans.empty() || ans.back() < seq[i])
		{
			ans.push_back(seq[i]);
		}
		else
		{
			int ind = BS(seq[i]);
			ans[ind] = seq[i];
		}
	}

	cout << ans.size();

	return 0;
}