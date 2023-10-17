#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	string a;
	string b;

	cin >> a;
	cin >> b;

	vector<vector<int>> LCS(a.length() + 1, vector<int>(b.length() + 1, 0));

	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	string result;

	int flag = LCS[a.length()][b.length()];
	int x = a.length();
	int y = b.length();

	while (flag != 0)
	{
		if (flag != LCS[x][y - 1] && flag != LCS[x - 1][y])
		{
			flag = LCS[--x][--y];
			result.push_back(a[x]);
		}
		else if (flag == LCS[x][y - 1])
		{
			y--;
		}
		else if (flag == LCS[x - 1][y])
		{
			x--;
		}
	}

	cout << result.length();
	if (result.length() > 0) 
	{
		cout << "\n";
		for (int i = result.length() - 1; i >= 0; i--)
		{
			cout << result[i];
		}
	}

	return 0;
}