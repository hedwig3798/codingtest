#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	stack<char> cs;
	int result = 0;
	int mul = 1;

	bool row = false;

	for (auto c : s)
	{
		if (c == ')' || c == ']')
		{
			if (cs.empty())
			{
				cout << 0; return 0;
			}

			if (!row)
			{
				result += mul;
			}
			row = true;
			if (c == ')' && cs.top() == '(')
			{
				mul /= 2;
				cs.pop();
			}
			else if (c == ']' && cs.top() == '[')
			{
				mul /= 3;
				cs.pop();
			}
			else
			{
				cout << 0; return 0;
			}
		}

		else if (c == '(' || c == '[')
		{
			row = false;
			cs.push(c);
			if (c == '(')
			{
				mul *= 2;
			}
			else if (c == '[')
			{
				mul *= 3;
			}
		}
	}

	if (!cs.empty())
	{
		cout << 0; return 0;
	}
	cout << result;
}