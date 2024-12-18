#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <limits.h> 
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;

int N;

int minAns = INT_MAX;
int maxAns = 0;

int ten[] =
{
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000
};

int CountOdd(int _num)
{
	int result = 0;
	while (_num > 0)
	{
		int n = _num % 10;
		if (n & 1)
			result++;

		_num *= 0.1;
	}
	return result;
}

void dfs(int _n, int _oddCount)
{
	if (_n < 10)
	{
		minAns = min(minAns, _oddCount);
		maxAns = max(maxAns, _oddCount);
		return;
	}

	if (_n < 100)
	{
		int front, back;
		front = (int)(_n * 0.1);
		back = _n % 10;

		int next = front + back;
		dfs(front + back, _oddCount + CountOdd(next));
	}
	else
	{
		for (int i = 1; i < 9; i++)
		{
			if (_n < ten[i] - 1)
				break;

			for (int j = i + 1; j < 9; j++)
			{
				if (_n < ten[j] - 1)
					break;

				int first, second, third;
				first = _n % ten[i];
				second = _n % ten[j] - first;
				third = _n - second - first;

				second /= ten[i];
				third /= ten[j];

				int next = first + second + third;
				dfs(next, _oddCount + CountOdd(next));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	dfs(N, CountOdd(N));

	cout << minAns << ' ' << maxAns;

	return 0;
}