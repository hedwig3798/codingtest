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

	int N, S;
	cin >> N >> S;

	vector<int> numbers(N);
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	int result = N;

	int start = 0;
	int end = 0;

	int acc = numbers[0];

	bool flag = false;

	while (true)
	{
		if (end == N - 1 && acc < S)
		{
			break;
		}

		if (acc >= S)
		{
			flag = true;
			result = min(end - start + 1, result);
			if (result == 1)
			{
				break;
			}
			acc -= numbers[start];
			start++;
		}
		else
		{
			end++;
			acc += numbers[end];
		}
	}

	if (flag)
	{
		cout << result;
	}
	else
	{
		cout << 0;

	}
	return 0;
}