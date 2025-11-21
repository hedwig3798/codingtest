#include <bits/stdc++.h>
#include <unordered_set>

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	std::priority_queue<int, std::vector<int>, std::greater<int>> n;
	std::priority_queue<int> p;
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int num;
		std::cin >> num;
		
		if (1 == num)
		{
			sum++;
			continue;
		}

		if (num <= 0)
		{
			n.push(num);
		}
		else
		{
			p.push(num);
		}
	}

	int ans = 0;
	while (false == n.empty())
	{
		int num1 = n.top();
		n.pop();
		if (true == n.empty())
		{
			ans += num1;
			break;
		}
		
		int num2 = n.top();
		n.pop();

		ans += num1 * num2;
	}

	while (false == p.empty())
	{
		int num1 = p.top();
		p.pop();
		if (true == p.empty())
		{
			ans += num1;
			break;
		}

		int num2 = p.top();
		p.pop();

		ans += num1 * num2;
	}

	std::cout << ans + sum;

	return 0;
}