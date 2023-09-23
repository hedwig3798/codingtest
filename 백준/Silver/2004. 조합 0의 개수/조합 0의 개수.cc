#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long d2(long long _a)	
{
	long long cnt = 0;
	for (long long i = 2; i <= _a; i *= 2)
	{
		cnt += _a / i;
	}
	return cnt;
}

long long d5(long long _a)	
{
	long long cnt = 0;
	for (long long i = 5; i <= _a; i *= 5)
	{
		cnt += _a / i;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	long long N, M;
	cin >> N >> M;

	long long result = min(d2(N) - d2(M) - d2(N - M), d5(N) - d5(M) - d5(N - M));
	cout << result;
	return 0;
}