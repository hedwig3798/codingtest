#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int T, N, M;

	cin >> T;

	cin >> N;
	vector<int> numN(N, 0);
	vector<int> sumN;
	for (int i = 0; i < N; i++)
	{
		cin >> numN[i];
	}

	for (int i = 0; i < N; i++)
	{
		int acc = numN[i];
		sumN.push_back(acc);
		for (int j = i + 1; j < N; j++)
		{
			acc += numN[j];
			sumN.push_back(acc);
		}
	}

	cin >> M;
	vector<int> numM(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> numM[i];
	}

	vector<int> sumM;
	for (int i = 0; i < M; i++)
	{
		int acc = numM[i];
		sumM.push_back(acc);
		for (int j = i + 1; j < M; j++)
		{
			acc += numM[j];
			sumM.push_back(acc);
		}
	}

	sort(sumM.begin(), sumM.end());

	long long result = 0;
	for (int i = 0; i < sumN.size(); i++)
	{
		int target = T - sumN[i];

		int first = lower_bound(sumM.begin(), sumM.end(), target) - sumM.begin();
		int last = upper_bound(sumM.begin(), sumM.end(), target) - sumM.begin();

		result += last - first;
	}
	cout << result;
	return 0;
}