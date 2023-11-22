#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>

#define INF 1e9
using namespace std;

long long N, S;
vector<long long> numbers(41, 0);
unordered_map<long long, long long> result;
long long ans = 0;

void LeftSide(long long _index, long long _sum)
{
	if (_index == N / 2)
	{
		result[_sum]++;
		return;
	}
	LeftSide(_index + 1, _sum);
	LeftSide(_index + 1, _sum + numbers[_index]);
}

void RightSide(long long _index, long long _sum)
{
	if (_index == N)
	{
		ans += result[S - _sum];
		return;
	}
	RightSide(_index + 1, _sum);
	RightSide(_index + 1, _sum + numbers[_index]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;

	for (long long i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	LeftSide(0, 0);
	RightSide(N / 2, 0);

	if (S == 0)
	{
		cout << ans - 1;
	}
	else
	{
		cout << ans;
	}

	return 0;
}