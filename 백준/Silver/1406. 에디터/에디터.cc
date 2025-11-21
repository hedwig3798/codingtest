#include <bits/stdc++.h>
#include <unordered_set>

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::stack<char> left;
	std::stack<char> right;

	std::string s;
	std::cin >> s;

	for (auto c : s)
	{
		left.push(c);
	}

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char command;
		std::cin >> command;

		switch (command)
		{
		case 'L':
		{
			if (false == left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;
		}
		case 'D':
		{
			if (false == right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;
		}
		case 'B':
		{
			if (false == left.empty())
			{
				left.pop();
			}
			break;
		}
		case 'P':
		{
			char op;
			std::cin >> op;
			left.push(op);
			break;
		}
		}
	}

	std::string ans;
	ans.resize(left.size());

	for (int i = left.size() - 1; i >= 0; --i)
	{
		ans[i] = left.top();
		left.pop();
	}

	while (false == right.empty())
	{
		ans.push_back(right.top());
		right.pop();
	}

	std::cout << ans;

	return 0;
}