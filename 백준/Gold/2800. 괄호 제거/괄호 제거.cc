#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

std::string s;
std::vector<pii> parIndex;

std::set<std::string> stringSet;

bool check[201] = { 0, };

std::stack<int> parIndexStack;

void GetIndex(int _depth)
{
	if (_depth == s.length())
	{
		return;
	}

	if (s[_depth] == '(')
	{
		parIndexStack.push(_depth);
	}
	else if (s[_depth] == ')')
	{
		parIndex.push_back({ parIndexStack.top(), _depth });
		parIndexStack.pop();
	}

	GetIndex(_depth + 1);
	return;
}

void GetAns(int _depth, bool _flag)
{
	if (_depth == parIndex.size()
		&& false == _flag)
	{
		std::string ans;
		for (int i = 0; i < s.size(); i++)
		{
			if ('(' == s[i]
				|| ')' == s[i])
			{
				if (true == check[i])
				{
					ans.push_back(s[i]);
				}
			}
			else
			{
				ans.push_back(s[i]);
			}
		}

		stringSet.insert(ans);
		return;
	}

	if (_depth == parIndex.size())
	{
		return;
	}

	check[parIndex[_depth].first] = true;
	check[parIndex[_depth].second] = true;
	GetAns(_depth + 1, _flag & true);
	check[parIndex[_depth].first] = false;
	check[parIndex[_depth].second] = false;
	GetAns(_depth + 1, false);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> s;

	GetIndex(0);

	std::sort(parIndex.begin(), parIndex.end());

	GetAns(0, true);

	for(auto& ans : stringSet)
	{
		std::cout << ans << '\n';
	}

	return 0;
}