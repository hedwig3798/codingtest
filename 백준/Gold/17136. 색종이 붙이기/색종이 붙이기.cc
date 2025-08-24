#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

bool paper[10][10];
int peice[5] = { 5, 5, 5, 5, 5 };

int ans = le9;

void DFS(int _x, int _y, int _count)
{
	// 넘치는 경우
	if (10 == _x || 10 == _y)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (true == paper[i][j])
				{
					return;
				}
			}
		}
		ans = std::min(ans, _count);
		return;
	}

	// 종이를 못붙이는 공간인 경우 다음 탐색
	if (false == paper[_x][_y])
	{
		if (_x == 9)
		{
			DFS(0, _y + 1, _count);
		}
		else
		{
			DFS(_x + 1, _y, _count);
		}
		return;
	}
	// 종이를 붙이는 공간인 경우
	else
	{
		// 큰 종이부터 붙여봄
		for (int i = 4; i >= 0; --i)
		{
			// 종이 갯수가 없는 경우
			if (peice[i] == 0)
			{
				continue;
			}

			// 종이를 붙이면 넘치는 경우
			if (i + _x >= 10
				|| i + _y >= 10)
			{
				continue;
			}

			// 종이를 붙일 수 있는지 확인
			bool check = true;
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0; k <= i; k++)
				{
					if (false == paper[j + _x][k + _y])
					{
						check = false;
						break;
					}
				}
				if (false == check)
				{
					break;
				}
			}

			// 못붙인다
			if (false == check)
			{
				continue;
			}
			else
			{
				// 현재 위치에 종이를 붙임
				peice[i]--;
				bool temp[10][10];
				for (int j = 0; j < i + 1; j++)
				{
					for (int k = 0; k < i + 1; k++)
					{
						temp[j + _x][k + _y] = paper[j + _x][k + _y];
						paper[j + _x][k + _y] = false;
					}
				}

				// 단계 증가
				if (_x == 9)
				{
					DFS(0, _y + 1, _count + 1);
				}
				else
				{
					DFS(_x + 1, _y, _count + 1);
				}

				// 복원
				peice[i]++;
				for (int j = 0; j < i + 1; j++)
				{
					for (int k = 0; k < i + 1; k++)
					{
						paper[j + _x][k + _y] = temp[j + _x][k + _y];
					}
				}
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cin >> paper[i][j];
		}
	}

	DFS(0, 0, 0);
	if (ans == le9)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << ans;
	}

	return 0;
}