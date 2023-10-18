#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

bool IsPan(int _s, int _e, vector<int>& seq)
{
	while (_s <= _e)
	{
		if (seq[_s++] != seq[_e--])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> seq(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}

	int M;
	cin >> M;

	vector<int> obbPan(N, -1);
	vector<int> evenPan(N, -1);

	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		--S;
		--E;

		int mid = (S + E) / 2;
		int range = E - S;

		if (range % 2 == 0)
		{
			if (obbPan[mid] >= range / 2)
			{
				cout << "1\n";
				continue;
			}
			else if (IsPan(S, E, seq)) 
			{
				cout << "1\n";
				obbPan[mid] = range / 2;
				continue;
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			if (evenPan[mid] >= range / 2)
			{
				cout << "1\n";
				continue;
			}
			else if (IsPan(S, E, seq))
			{
				cout << "1\n";
				evenPan[mid] = range / 2;
				continue;
			}
			else
			{
				cout << "0\n";
			}
		}

	}

	return 0;
}