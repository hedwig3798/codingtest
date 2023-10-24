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

	if (N == 1) 
	{
		cout << 0;
		return 0;
	}
	if (N == 2) 
	{
		cout << 1;
		return 0;
	}
	if (N == 3)
	{
		cout << 1;
		return 0;
	}

	vector<bool>isPrime(N + 1, true);
	vector<int> primes;

	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;

	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i] == false)
		{
			continue;
		}
		primes.push_back(i);
		for (int j = i * 2; j <= N; j += i)
		{
			isPrime[j] = false;
		}
	}

	int start = 0;
	int end = 1;
	int result = primes[start] + primes[end];;
	int count = 0;

	while (start < end && end < primes.size())
	{
		if (result == N) 
		{
			count++;
			end++;
			result += primes[end];
			continue;
		}
		if (result < N) 
		{
			end++;
			result += primes[end];
			continue;
		}
		if (result > N) 
		{
			result -= primes[start];
			start++;
			continue;
		}

	}
	if (primes.back() == N) 
	{
		count++;
	}
	cout << count;

	return 0;
}