#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int bs(int _target, int _left, int _right, vector<int>& _vec)
{

	while (_left < _right)
	{
		int mid = (_left + _right) / 2;
		if (_target <= _vec[mid])
		{
			_right = mid;
		}
		else
		{
			_left = mid + 1;
		}

	}
	return _left;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> numbers;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	vector<int> lis;
	vector<int> index;

	lis.push_back(numbers[0]);
	index.push_back(0);

	for (int i = 1; i < N; i++)
	{
		if (numbers[i] > lis.back())
		{
			lis.push_back(numbers[i]);
			index.push_back((int)lis.size() - 1);
		}
		else
		{
			int ind = bs(numbers[i], 0, (int)lis.size() - 1, lis);
			lis[ind] = numbers[i];
			index.push_back(ind);
		}
	}

	cout << lis.size() << "\n";

	int now = (int)lis.size() - 1;
	vector<int> result;

	for (int i = (int)index.size() - 1; i >= 0; i--)
	{
		if (now == index[i])
		{
			result.push_back(numbers[i]);
			now--;
		}
	}

	sort(result.begin(), result.end());

	for (auto r : result)
	{
		cout << r << " ";
	}

	return 0;
}