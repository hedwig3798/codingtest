#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 10'001

int N, M;

std::vector<std::pair<int, int>> islands[MAX_COUNT];
bool isVisit[MAX_COUNT] = { 0, };
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		std::cin >> A >> B >> C;
		islands[A].push_back({ C, B });
		islands[B].push_back({ C, A });
	}

	int start, end;
	std::cin >> start >> end;

	isVisit[start] = true;
	std::priority_queue<std::pair<int, int>> pq;

	pq.push({ INT_MAX, start });

	while (false == pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		int cNode = curr.second;
		int cCost = curr.first;

		if (cNode == end)
		{
			std::cout << cCost;
			return 0;
		}

		isVisit[cNode] = true;

		for (auto& itr : islands[cNode])
		{
			if (true == isVisit[itr.second])
			{
				continue;
			}

			pq.push({ std::min(itr.first, cCost), itr.second });
		}
	}

	return 0;
}