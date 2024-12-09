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

int F;
unordered_map<string, pair<string, int>> friendUnion;

string& Find(string& _a)
{
	if (friendUnion[_a].first == _a)
	{
		return _a;
	}
	return friendUnion[_a].first = Find(friendUnion[_a].first);
}



int Union(string& _parent, string& _child)
{
	string& parentP = Find(_parent);
	string& childP = Find(_child);

	if (parentP == childP)
	{
		return friendUnion[parentP].second;
	}

	friendUnion[childP].first = parentP;
	friendUnion[parentP].second += friendUnion[childP].second;

	return friendUnion[parentP].second;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++)
	{
		cin >> F;
		friendUnion = unordered_map<string, pair<string, int>>();
		for (int i = 0; i < F; i++)
		{
			string a, b;
			cin >> a >> b;

			if (friendUnion.find(a) == friendUnion.end())
			{
				friendUnion[a] = { a, 1 };
			}
			if (friendUnion.find(b) == friendUnion.end())
			{
				friendUnion[b] = { b, 1 };
			}

			cout << Union(a, b) << "\n";
		}
	}

	return 0;
}