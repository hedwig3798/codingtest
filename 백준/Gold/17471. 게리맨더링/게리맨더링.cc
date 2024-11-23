#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>

#define INF 1e9
#define MOD 1'000'000'000;
typedef long long ll;

using namespace std;

unsigned int N;

unsigned int ans = INF;

vector<int> population;

vector<vector<int>> city;

unsigned int totalPopulation = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	population = vector<int>(N);
	city = vector<vector<int>>(N);

	unsigned int maxCount = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> population[i];
		totalPopulation += population[i];

		maxCount |= 1 << i;
	}

	for (int i = 0; i < N; i++)
	{
		int count;
		cin >> count;
		for (int j = 0; j < count; j++)
		{
			int c;
			cin >> c;
			city[i].push_back(c - 1);
		}
	}

	for (unsigned int i = 1; i < maxCount; i++)
	{
		unsigned int flag = i;
		unsigned int groupAPop = 0;
		unsigned int groupBPop = 0;

		vector<bool> grouped(N, false);

		int startA = -1, startB = -1;

		for (unsigned int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				groupAPop += population[j];
				startA = j;
				grouped[j] = true;
			}
			else
			{
				grouped[j] = false;
				groupBPop += population[j];
				startB = j;
			}
		}

		int diff = abs((int)(groupAPop) - (int)(groupBPop));

		bool correct = true;
		if (diff < ans)
		{
			queue<int> qA;
			vector<bool> isVisitA(N, false);
			qA.push(startA);
			isVisitA[startA] = true;

			while (!qA.empty())
			{
				int curr = qA.front();
				qA.pop();

				for (auto& c : city[curr])
				{
					if (!grouped[c] || isVisitA[c])
						continue;

					isVisitA[c] = true;
					qA.push(c);
				}
			}

			for (int j = 0; j < N; j++)
			{
				if (!(grouped[j] == isVisitA[j]))
				{
					correct = false;
					break;
				}
			}

			if (!correct)
			{
				continue;
			}

			queue<int> qB;
			vector<bool> isVisitB(N, false);
			qB.push(startB);
			isVisitB[startB] = true;

			while (!qB.empty())
			{
				int curr = qB.front();
				qB.pop();

				for (auto& c : city[curr])
				{
					if (grouped[c] || isVisitB[c])
						continue;

					isVisitB[c] = true;
					qB.push(c);
				}
			}

			for (int j = 0; j < N; j++)
			{
				if (!(!grouped[j] == isVisitB[j]))
				{
					correct = false;
					break;
				}
			}

			if (!correct)
			{
				continue;
			}

			ans = diff;
		}


	}

	if (ans == INF)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}