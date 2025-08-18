#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

struct net
{
	int cost;
	int to;
	int from;


};

vector<int> uf;
vector<net> network;

bool Compare(const net& _a, const net& _b)
{
	return _a.cost < _b.cost;
}

int Converter(char _a)
{
	if (_a >= 'a' && _a <= 'z')
	{
		return _a - 'a' + 1;
	}
	else if (_a >= 'A' && _a <= 'Z')
	{
		return _a - 'A' + 27;
	}

	return 0;
}

int GetParent(int _a)
{
	if (uf[_a] == _a)
	{
		return _a;
	}

	return uf[_a] = GetParent(uf[_a]);
}

void Union(int _a, int _b)
{
	int ap = GetParent(_a);
	int bp = GetParent(_b);

	uf[ap] = bp;
}

bool CheckUnion()
{
	for (int i = 0; i < uf.size() - 1 ; i++)
	{
		if (GetParent(i) != GetParent(i + 1))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;

	cin >> n;

	uf.resize(n);
	int totalLenth = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			char c = s[j];

			int con = Converter(c);

			totalLenth += con;
			if (con == 0)
			{
				continue;
			}
			network.push_back({ con, i, j });
		}

		uf[i] = i;
	}

	std::sort(network.begin(), network.end(), Compare);

	for(auto& n : network)
	{
		if (GetParent(n.to) != GetParent(n.from))
		{
			Union(n.to, n.from);
			totalLenth -= n.cost;
		}
	}

	if (!CheckUnion())
	{
		cout << -1;
		return 0;
	}

	cout << totalLenth;

	return 0;
}