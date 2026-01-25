#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 100'001

int N, R, Q;

std::vector<int> tree[MAX_COUNT];
bool isVisit[MAX_COUNT] = { 0, };
int subCount[MAX_COUNT] = { 0, };

int DFS(int _now)
{
	if (true == isVisit[_now])
	{
		return 0;
	}

	isVisit[_now] = true;
	subCount[_now] = 1;
	for(auto& child : tree[_now])
	{
		subCount[_now] += DFS(child);
	}

	return subCount[_now];
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> R >> Q;

	for (int i = 0; i < N - 1 ; i++)
	{
		int a, b;
		std::cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(R);

	for (int i = 0; i < Q ; i++)
	{
		int q;
		std::cin >> q;

		std::cout << subCount[q] << '\n';
	}

	return 0;
}