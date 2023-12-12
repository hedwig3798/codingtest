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

int R, C;
int M;

struct Shark
{
	int x = 0;
	int y = 0;
	int speed = 0;
	int dirX = 0;
	int dirY = 0;
	int size = 0;
	int id = 0;
};

void Move(Shark& _s)
{
	_s.x += _s.dirX * _s.speed;
	while (_s.x < 1 || _s.x > R)
	{
		if (_s.x < 1)
		{
			_s.x *= -1;
			_s.x += 2;
			_s.dirX *= -1;
		}
		else if (_s.x > R)
		{
			_s.dirX *= -1;
			_s.x = 2 * R - _s.x;
		}
	}

	_s.y += _s.dirY * _s.speed;
	while (_s.y < 1 || _s.y > C)
	{
		if (_s.y < 1)
		{
			_s.y *= -1;
			_s.y += 2;
			_s.dirY *= -1;
		}
		else if (_s.y > C)
		{
			_s.dirY *= -1;
			_s.y = 2 * C - _s.y;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> M;

	vector<Shark> sharks;
	vector<vector<Shark>> fishing(R + 1, vector<Shark>(C + 1, { 0, }));

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		Shark newShark;
		newShark.x = r;
		newShark.y = c;
		newShark.speed = s;
		newShark.size = z;

		switch (d)
		{
		case 1:
			newShark.dirX = -1;
			break;
		case 2:
			newShark.dirX = 1;
			break;
		case 3:
			newShark.dirY = 1;
			break;
		case 4:
			newShark.dirY = -1;
			break;
		default:
			break;
		}
		newShark.id = i;
		fishing[r][c] = newShark;
		sharks.push_back(newShark);
	}

	int ans = 0;

	for (int i = 1; i <= C; i++)
	{
		int fish = 0;
		for (int j = 1; j <= R; j++)
		{
			if (fishing[j][i].size != 0)
			{
				fish = fishing[j][i].size;
				sharks[fishing[j][i].id].size = 0;
				break;
			}
		}
		ans += fish;
		fishing = vector<vector<Shark>>(R + 1, vector<Shark>(C + 1, { 0, }));


		for (int a = 0; a < sharks.size(); a++)
		{
			if (sharks[a].size == 0)
			{
				continue;
			}
			Move(sharks[a]);

			if (fishing[sharks[a].x][sharks[a].y].size == 0)
			{
				fishing[sharks[a].x][sharks[a].y] = sharks[a];
			}
			else
			{
				if (fishing[sharks[a].x][sharks[a].y].size > sharks[a].size)
				{
					sharks[a].size = 0;
				}
				else
				{
					sharks[fishing[sharks[a].x][sharks[a].y].id].size = 0;
					fishing[sharks[a].x][sharks[a].y] = sharks[a];
				}
			}
		}
	}
	cout << ans;
	return 0;
}