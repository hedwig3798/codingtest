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
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> W_C(N);

	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;

		W_C[i] = make_pair(M, V);
	}
	sort(W_C.begin(), W_C.end());

	vector<int> bag;
	for (int i = 0; i < K; i++)
	{
		int w;
		cin >> w;
		bag.push_back(w);
	}
	sort(bag.begin(), bag.end());

	long long result = 0;
	int ind = 0;

	priority_queue<int> pq;
	for (int i = 0; i < bag.size(); i++)
	{
		while (ind < W_C.size() && bag[i] >= W_C[ind].first)
		{
			pq.push(W_C[ind].second);
			ind++;
		}
		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
	return 0;
}