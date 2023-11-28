#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second 
int n;

int board[10][10];
bool isused1[20];
bool isused2[20];
int ans = 0;
void bishop(int th, int size)
{

	if (th >= 2 * n - 1)
	{
		ans = max(ans, size);
	}
	else
	{
		bool flag = false;
		for (int j = 0; j < n - abs(th - (n - 1)); j++)
		{
			int x = (n - 1 <= th) ? n - 1 - j : th - j;
			int y = (n - 1 <= th) ? th - (n - 1) + j : j;
			if (board[x][y] == 1 && !isused1[th] && !isused2[n - 1 + (x - y)])
			{
				flag = true;
				isused1[th] = true;
				isused2[n - 1 + (x - y)] = true;
				bishop(th + 1, size + 1);
				isused1[th] = false;
				isused2[n - 1 + (x - y)] = false;

			}
		}
		if (!flag)
			bishop(th + 1, size);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	bishop(0, 0);
	cout << ans;
}
