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
#define MOD 1'000'000'007

using namespace std;
using ll = long long;

vector<vector<ll>> board =
{
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

vector<vector<ll>> ans(8, vector<ll>(8, 0));

void Multiply(vector<vector<ll>>& _matrix1, vector<vector<ll>>& _matrix2)
{
	vector<vector<ll>> result(8, vector<ll>(8, 0));
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			ll temp = 0;
			for (int k = 0; k < 8; k++) 
			{
				temp += (_matrix1[i][k] * _matrix2[k][j]);
				temp %= MOD;
			}
			result[i][j] = temp;
		}
	}

	_matrix1 = result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll D;
	cin >> D;

	for (int i = 0; i < 8; i++)
	{
		ans[i][i] = 1;
	}

	while (D > 0)
	{
		if (D & 1) 
		{
			Multiply(ans, board);
			D--;
		}
		Multiply(board, board);
		D = D >> 1;
	}

	cout << ans[0][0];
}