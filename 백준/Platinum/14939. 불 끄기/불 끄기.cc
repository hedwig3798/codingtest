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

vector<vector<bool>> light(10, vector<bool>(10, false));

int ans = INF;

int dx[] = { 1, 0, -1, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0 };


void PrintVec(vector<vector<bool>>& _light)
{
	cout << '\n';
	for(auto li : _light) 
	{
		for(auto l : li) 
		{
			if (l) 
			{
				cout << 'O';
			}
			else
			{
				cout << '#';
			}
		}
		cout << '\n';
	}
}


void Click(int _x, int _y, vector<vector<bool>>& _light)
{
	for (int i = 0; i < 5; i++)
	{
		int cx = _x + dx[i];
		int cy = _y + dy[i];

		if (cx < 0 || cy < 0 || cx >= 10 || cy >= 10)
		{
			continue;
		}
		_light[cx][cy] = !_light[cx][cy];
	}
}

int Greedy(int _count, vector<vector<bool>> _light)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_light[i - 1][j])
			{
				Click(i, j, _light);
				_count++;
				// PrintVec(_light);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (_light[9][i])
		{
			return INF;
		}
	}

	return _count;
}

void DFS(int _depth, int _count)
{
	if (_depth == 10)
	{
		//PrintVec(light);
		ans = min(ans, Greedy(_count, light));
		return;
	}


	// PrintVec(light);
	DFS(_depth + 1, _count);

	Click(0, _depth, light);
	// PrintVec(light);
	DFS(_depth + 1, _count + 1);
	Click(0, _depth, light);
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			char a;
			cin >> a;
			if (a == '#')
			{
				light[i][j] = false;
			}
			else
			{
				light[i][j] = true;
			}
		}
	}

	DFS(0, 0);

	if (ans == INF) 
	{
		cout << -1;
		return 0;
	}

	cout << ans;

	return 0;
}