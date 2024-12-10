#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int game = 0;
	for (int i = 0; i < n ; i++)
	{
		int stone;
		cin >> stone;

		game ^= stone;
	}

	if (game)
	{
		cout << "koosaga";
	}
	else
	{
		cout << "cubelover";
	}
	return 0;
}