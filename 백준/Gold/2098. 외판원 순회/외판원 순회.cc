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

int W[16][16];
int isVisit[16][1 << 16];
// vector<vector<int>>isVisit (16, vector<int>((1 << 16), INF));
int N;

int TSP(int _now, int _visit)
{
	if (_visit == (1 << N) - 1) 
	{
		if (W[_now][0] == 0)
		{
			return INF;
		}
		return isVisit[_now][_visit] + W[_now][0];
	}

	if (isVisit[_now][_visit] != -1)
	{
		return isVisit[_now][_visit];
	}

	isVisit[_now][_visit] = INF;


	for (int i = 0; i < N; i++)
	{
		if (_visit & (1 << i)) 
		{
			continue;
		}
		if (W[_now][i] == 0)
		{
			continue;
		}
		int next = _visit + (1 << i);

		isVisit[_now][_visit] = min(isVisit[_now][_visit], TSP(i, _visit | 1 << i) + W[_now][i]);
	}

	return isVisit[_now][_visit];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	memset(isVisit, -1, sizeof(isVisit));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	int result = INF;

	result = min(result, TSP(0, 1 << 0));

	cout << result + 1;

	return 0;
}