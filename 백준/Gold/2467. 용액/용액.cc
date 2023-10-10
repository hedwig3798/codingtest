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

	vector<int> liquid;

	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		liquid.push_back(value);
	}

	int result = 2e9;
	int resultStart = 0, resultEnd = 0;

	int start = 0;
	int end = liquid.size() - 1;

	while (start != end)
	{
		if (abs(liquid[start] + liquid[end]) < result)
		{
			resultStart = start;
			resultEnd = end;
			result = abs(liquid[start] + liquid[end]);
		}
		int aStart = abs(liquid[start]);
		int aEnd = abs(liquid[end]);
		if (aStart == aEnd)
		{
			break;
		}
		else if (aStart > aEnd)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << liquid[resultStart] << " " << liquid[resultEnd];

	return 0;
}