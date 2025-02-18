#include <bits/stdc++.h>


#define le9 1'000'000'000
using namespace std;

int N;

int robot[1'000'001] = { 0, };
int compCount[1'000'001] = { 0, };

int GetParent(int _a)
{
	if (_a == robot[_a])
	{
		return _a;
	}

	robot[_a] = GetParent(robot[_a]);

	return robot[_a];
}

void Union(int _a, int _b)
{
	int pa = GetParent(_a);
	int pb = GetParent(_b);

	if (pa == pb)
	{
		return;
	}

	robot[pb] = pa;
	compCount[pa] += compCount[pb];
	compCount[pb] = 0;
}

int GetCompCount(int _a)
{
	int pa = GetParent(_a);

	return compCount[pa];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 1; i < 1000001; i++) 
	{
		robot[i] = i;
		compCount[i] = 1;
	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char order;
		cin >> order;

		if (order == 'I')
		{
			int a, b;
			cin >> a >> b;

			Union(a, b);
		}
		else
		{
			int r;
			cin >> r;

			cout << GetCompCount(r) << '\n';
		}
	}


	return 0;
}