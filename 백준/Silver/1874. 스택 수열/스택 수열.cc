#include <bits/stdc++.h>
#include <unordered_set>

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::stack<int> s;
	std::cin >> N;
	std::vector<int> seq(N);
	std::string ans = "";

	for (int i = 0; i < N; ++i)
	{
		std::cin >> seq[i];
	}

	int now = 1;
	int index = 0;

	while (true)
	{
		if (index < N 
			&& now == seq[index])
		{
			ans += "+-";
			index++;
			now++;
		}
		else if (false == s.empty()
			&& index < N
			&& s.top() == seq[index])
		{
			index++;
			ans += "-";
			s.pop();
		}
		else if (now <= N)
		{
			ans += "+";
			s.push(now);
			now++;
		}
		else
		{
			break;
		}
	}

	if (false == s.empty())
	{
		std::cout << "NO";
	}
	else
	{
		for(auto c : ans)
		{
			std::cout << c << "\n";
		}
	}

	return 0;
}