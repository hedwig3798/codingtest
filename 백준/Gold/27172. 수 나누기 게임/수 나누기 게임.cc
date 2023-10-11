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
	int maximum = 1'000'001;
	cin >> N;

	vector<int> numbers(N);
	vector<int> score(maximum, 0);
	vector<bool> isEixsist(maximum, false);

	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		numbers[i] = number;
		isEixsist[number] = true;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = numbers[i] * 2; j < maximum; j += numbers[i])
		{
			if (isEixsist[j])
			{
				score[j]--;
				score[numbers[i]]++;
			}
		}
	}

	for (auto n : numbers)
	{
		cout << score[n] << " ";
	}

	return 0;
}