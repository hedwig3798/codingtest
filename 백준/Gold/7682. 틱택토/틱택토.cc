#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

string s;
int Xcount = 0, OCount = 0;

bool CheckCount()
{
	Xcount = 0, OCount = 0;
	for (auto c : s)
	{
		if (c == 'X')
		{
			Xcount++;
		}
		else if (c == 'O')
		{
			OCount++;
		}
	}

	if (Xcount == OCount || Xcount == OCount + 1)
	{
		return true;
	}
	return false;
}

bool CheckWinCase()
{
	char winCase[8] = {0, };
	for (int i = 0; i < 9; i += 3)
	{
		if (s[i] == '.')
		{
			continue;
		}
		
		
		if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2]))
		{
			winCase[i / 3] = s[i];	
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (s[i] == '.')
		{
			continue;
		}

		if ((s[i] == s[i + 3]) && (s[i + 3] == s[i + 6]))
		{
			winCase[i + 3] = s[i];
		}
	}
	if ((s[0] != '.') && (s[0] == s[4]) && (s[4] == s[8]))
	{
		winCase[6] = s[0];
	}
	if ((s[2] != '.') && (s[2] == s[4]) && (s[4] == s[6]))
	{
		winCase[7] = s[4];
	}

	int winCountX = 0;
	int winCountO = 0;

	for (int i = 0; i < 8; i++)
	{
		if (winCase[i] == 'X')
		{
			winCountX++;
		}
		else if (winCase[i] == 'O')
		{
			winCountO++;
		}
	}

	if (winCountO >= 2 || winCountX >= 3 || (winCountX >= 1 && winCountO >= 1))
	{
		return false;
	}

	if (winCountO == 1 && winCountX == 0)
	{
		if (OCount != Xcount)
		{
			return false;
		}
	}

	if (winCountO == 0 && winCountX >= 1)
	{
		if (OCount != Xcount - 1)
		{
			return false;
		}
	}

	if (winCountO == 0 && winCountX == 0 && OCount + Xcount != 9)
	{
		return false;
	}

	if ((winCase[0] && winCase[2]) || (winCase[3] && winCase[5]))
	{
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true)
	{
		s.clear();
		cin >> s;

		if (s == "end")
		{
			return 0;
		}

		if (CheckCount() && CheckWinCase())
		{
			cout << "valid\n";
		}
		else
		{
			cout << "invalid\n";
		}
	}

	return 0;
}