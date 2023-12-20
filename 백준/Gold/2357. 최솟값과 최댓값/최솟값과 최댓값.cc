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
#include <memory.h>

#define INF (int)1e9
using namespace std;

int N, M;

vector<int> minTree;
vector<int> maxTree;
vector<int> numData;

int MinQuary(int _left, int _right)
{
	int result = INF;

	for (_left += N, _right += N; _left < _right; _left >>= 1, _right >>= 1)
	{
		if (_left & 1) 
		{
			result = min(result, minTree[_left++]);
		}
		if (_right & 1) 
		{
			result = min(result, minTree[--_right]);
		}
	}
	return result;
}

int MaxQuary(int _left, int _right)
{
	int result = 0;

	for (_left += N, _right += N; _left < _right; _left >>= 1, _right >>= 1)
	{
		if (_left & 1)
		{
			result = max(result, maxTree[_left++]);
		}
		if (_right & 1)
		{
			result = max(result, maxTree[--_right]);
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	numData.resize(N);
	minTree.resize(N * 2);
	maxTree.resize(N * 2);
	for (int i = 0; i < N; i++)
	{
		cin >> numData[i];
		minTree[i + N] = numData[i];
		maxTree[i + N] = numData[i];
	}

	for (int i = N - 1; i > 0; i--)
	{
		minTree[i] = min(minTree[(i << 1)], minTree[(i << 1) | 1]);
	}

	for (int i = N - 1; i > 0; i--)
	{
		maxTree[i] = max(maxTree[(i << 1)], maxTree[(i << 1) | 1]);
	}

	for (int i = 0; i < M; i++)
	{
		int left, right;
		cin >> left >> right;

		cout << MinQuary(left - 1, right);
		cout << " ";
		cout << MaxQuary(left - 1, right);
		cout << "\n";
	}

	return 0;
}