#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

void Update(long long _pos, long long _value, vector<long long>& _sTree, int N)
{
	_sTree[_pos + N] = _value;
	for (_pos += N; _pos > 1; _pos >>= 1)
	{
		_sTree[_pos >> 1] = _sTree[_pos] + _sTree[_pos ^ 1];
	}
}

long long Query(long long _left, long long _right, vector<long long>& _sTree, int N)
{
	long long result = 0;
	for (_left += N, _right += N; _left < _right; _left >>=1, _right >>= 1)
	{
		if (_left & 1) 
		{
			result += _sTree[_left++];
		}
		if (_right & 1) 
		{
			result += _sTree[--_right];
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<long long, int>> vec;
	vector<long long> sTree(N * 2, 0);
	for (int i = 0; i < N; i++)
	{
		long long num;
		cin >> num;
		vec.push_back({ num, i });
	}

	sort(vec.begin(), vec.end());

	long long result = 0;
	for (int i = 0; i < N; i++)
	{
		result += Query(vec[i].second + 1, N, sTree, N);
		Update(vec[i].second, 1, sTree, N);
	}

	cout << result;
}