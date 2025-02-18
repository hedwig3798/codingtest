#include <bits/stdc++.h>


#define le9 1'000'000'000
using namespace std;

int N;

int StrSum(string& _a)
{
	int result = 0;
	for (auto& c : _a)
	{
		if (c >= '0' && c <= '9')
		{
			result += c - '0';
		}
	}

	return result;
}

bool Dictional(string& _a, string& _b)
{
	for (int i = 0; i < _a.size(); i++)
	{
		if (_a[i] < _b[i])
		{
			return true;
		}
		else if (_a[i] > _b[i])
		{
			return false;
		}
	}
}

bool CMP(string& _a, string& _b)
{
	if (_a.length() < _b.length())
	{
		return true;
	}
	else if (_a.length() > _b.length())
	{
		return false;
	}

	int sa = StrSum(_a);
	int sb = StrSum(_b);

	if (sa < sb)
	{
		return true;
	}
	else if (sa > sb)
	{
		return false;
	}

	return Dictional(_a, _b);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	vector<string> ans(N);

	for (int i = 0; i < N; i++)
	{
		cin >> ans[i];
	}

	sort(ans.begin(), ans.end(), CMP);

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << '\n';
	}


	return 0;
}