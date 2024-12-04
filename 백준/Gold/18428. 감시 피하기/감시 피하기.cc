#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;


int N;
vector<vector<char>> table;

vector<pii> student;
vector<pii> teacher;
set<pii> sight;

int dx[] = {1, 0, -1 ,0};
int dy[] = {0, 1, 0, -1};

bool FindStudent()
{
	for (auto& pos : teacher)
	{
		for (int i = 0; i < 4 ; i++)
		{
			int x = pos.first;
			int y = pos.second;

			while (true)
			{
				x += dx[i];
				y += dy[i];
				if (x < 0 || y < 0 || x >= N || y >= N)
					break;

				if (table[x][y] == 'O')
					break;

				if (table[x][y] == 'S')
					return true;
			}
		}
	}

	return false;
}

bool SetObstacle(int _depth, int _x, int _y)
{



	if (_depth == 3)
	{
		return FindStudent();
	}

};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	table = vector<vector<char>>(N, vector<char>(N));

	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N ; j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 'S')
				student.push_back({ i, j });
			else if (table[i][j] == 'T')
				teacher.push_back({ i, j });
		}
	}

	for (auto& pos : teacher)
	{
		for (int i = 0; i < 4; i++)
		{
			int x = pos.first;
			int y = pos.second;

			while (true)
			{
				x += dx[i];
				y += dy[i];
				if (x < 0 || y < 0 || x >= N || y >= N)
					break;

				if (table[x][y] == 'X')
				{
					sight.insert({ x, y });
				}
			}
		}
	}

	vector<pii> sightVec;
	for (auto& s : sight)
	{
		sightVec.push_back(s);
	}

	int size = sightVec.size();
	for (int i = 0; i < size; i++)
	{
		pii f = sightVec[i];
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				continue;
			pii s = sightVec[j];
			for (int k = 0; k < size ; k++)
			{
				if (k == j)
					continue;
				pii t = sightVec[k];

				table[f.first][f.second] = 'O';
				table[s.first][s.second] = 'O';
				table[t.first][t.second] = 'O';

				if (!FindStudent())
				{
					cout << "YES";
					return 0;
				}

				table[f.first][f.second] = 'X';
				table[s.first][s.second] = 'X';
				table[t.first][t.second] = 'X';
			}
		}
	}
	cout << "NO";
	return 0;
}