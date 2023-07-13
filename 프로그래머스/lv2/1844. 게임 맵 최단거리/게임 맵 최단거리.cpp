#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 105;
const int INT_MAX = 99999999;

int minAnswer = INT_MAX;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int visMat[MAXSIZE][MAXSIZE] = { 0, };


int solution(vector<vector<int>> maps)
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visMat[0][0] = true;

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> temp = { now.first + dx[i], now.second + dy[i] };

			if (temp.first < 0 || temp.second < 0 || temp.first >= maps[0].size() || temp.second >= maps.size())
			{
				continue;
			}
			if (maps[temp.second][temp.first] == 0)
			{
				continue;
			}
			if (visMat[temp.second][temp.first] != 0)
			{
				continue;
			}
			q.push(temp);
			visMat[temp.second][temp.first] = visMat[now.second][now.first] + 1;
		}
	}
	if (visMat[maps.size() - 1][maps[0].size() - 1] == 0)
	{
		return -1;
	}
	return  visMat[maps.size() - 1][maps[0].size() - 1];
}