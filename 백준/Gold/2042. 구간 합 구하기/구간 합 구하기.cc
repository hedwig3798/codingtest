#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

long long streeInit(vector<long long>& stree, vector<long long>& numbers, long long start, long long end, long long index)
{
	if (start == end) 
	{
		stree[index] = numbers[start];
		return stree[index];
	}

	long long mid = (start + end) / 2;

	stree[index] = 
		streeInit(stree, numbers, start, mid, index * 2) + 
		streeInit(stree, numbers, mid + 1, end, index * 2 + 1);
	return stree[index];
}

long long getSum(vector<long long>& stree, long long start, long long end, long long index, long long left, long long right)
{
	if (left > end || right < start) 
	{
		return 0;
	}

	if (left <= start && right >= end) 
	{
		return stree[index];
	}

	long long mid = (start + end) / 2;

	return getSum(stree, start, mid, index * 2, left, right) +
		getSum(stree, mid + 1, end, index * 2 + 1, left, right);
}

void update(vector<long long>& stree, long long start, long long end, long long index, long long wh, long long val)
{
	if (wh < start || wh > end)
	{
		return;
	}

	stree[index] += val;
	
	if (start == end) 
	{
		return;
	}

	long long mid = (start + end) / 2;

	update(stree, start, mid, index * 2, wh, val);
	update(stree, mid + 1, end, index * 2 + 1, wh, val);
}

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> numbers;

	vector<long long> stree (4000004, 0);

	for (long long i = 0; i < n; i++)
	{
		long long input;
		cin >> input;
		numbers.push_back(input);
	}

	streeInit(stree, numbers, 0, n-1, 1);

	for (long long i = 0; i < m + k; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		switch (a)
		{
			case 1:
			{
				update(stree, 1, n, 1, b, c - numbers[b-1]);
				numbers[b - 1] = c;
				break;
			}
			case 2:
			{
				cout << getSum(stree, 1, n, 1, b, c) << "\n";
				break;
			}
		}
	}

	return 0;
}