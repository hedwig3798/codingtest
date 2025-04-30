#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N;
const int MAX_TREE = 100'000;

int targetHight;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	int r2 = 0;
	int total = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> targetHight;
		r2 += targetHight / 2;
		total += targetHight;
	}

	if (total % 3 != 0)
	{
		cout << "NO";
	}
	else if (r2 >= total / 3)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}



	return 0;
}