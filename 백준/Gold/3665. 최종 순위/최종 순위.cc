#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

int T;



int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> T;
	while (0 < T--)
	{
		int N;
		std::cin >> N;

		int indegree[501] = { 0, };
		bool ranks[501][501] = { 0, };
		std::vector<int> input;
		for (int i = 0; i < N; i++)
		{
			int r;
			std::cin >> r;
			input.push_back(r);

			indegree[r] = i;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				ranks[input[i]][input[j]] = true;
			}
		}


		int c;
		std::cin >> c;
		for (int i = 0; i < c; i++)
		{
			int a, b;
			std::cin >> a >> b;

			if (true == ranks[a][b])
			{
				ranks[a][b] = false;
				ranks[b][a] = true;
				indegree[a]++;
				indegree[b]--;
			}
			else if (true == ranks[b][a])
			{
				ranks[a][b] = true;
				ranks[b][a] = false;
				indegree[b]++;
				indegree[a]--;
			}
		}

		std::queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (0 == indegree[i])
			{
				q.push(i);
			}
		}

		if (1 < q.size())
		{
			std::cout << "?\n";
			continue;
		}

		std::vector<int> ans;
		while (false == q.empty())
		{
			int curr = q.front();
			q.pop();

			ans.push_back(curr);

			int count = 0;
			for (int i = 1; i <= N; i++)
			{
				if (true == ranks[curr][i])
				{
					indegree[i]--;
					if (0 == indegree[i])
					{
						q.push(i);
						count++;
					}
				}
			}

			if (1 < count)
			{
				std::cout << "?\n";
				continue;
			}
		}

		if (ans.size() != N)
		{
			std::cout << "IMPOSSIBLE\n";
			continue;
		}

		for(auto& itr : ans)
		{
			std::cout << itr << ' ';
		}
		std::cout << '\n';
		continue;
	}


	return 0;
}