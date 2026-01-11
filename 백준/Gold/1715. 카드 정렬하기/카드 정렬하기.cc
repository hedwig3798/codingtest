#include <bits/stdc++.h>
#include <unordered_set>

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	long long ans = 0;
	std::priority_queue<long long> pq;
	for (int i = 0; i < N ; i++)
	{
		int num;
		std::cin >> num;
		pq.push(-num);
	}

	while (1 != pq.size())
	{
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();

		pq.push(-(a + b));

		ans += a + b;
	}

	std::cout << ans;

	return 0;
}