#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

#define INF 1e9
#define MOD 100'000;

typedef long long ll;

typedef pair<int, int> pii;

int N, K;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	if (N == K)
	{
		cout << 0 << "\n" << N;
		return 0;
	}

	queue<int> q;
	q.push(N);

	vector<int> isVisit(100'001, -1);
	isVisit[N] = N;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		int x[] = {curr + 1, curr - 1, curr * 2};

		for (int i = 0; i < 3 ; i++)
		{
			if (x[i] < 0 || x[i] > 100'000 || isVisit[x[i]] != -1)
			{
				continue;
			}

			isVisit[x[i]] = curr;

			if (x[i] == K)
			{
				stack<int> s;
				int ans = K;

				while (ans != N)
				{
					s.push(ans);
					ans = isVisit[ans];
				}
				cout << s.size() << "\n";
				cout << N << " ";
				while (!s.empty())
				{
					cout << s.top() << " ";
					s.pop();
				}
				return 0;
			}

			q.push(x[i]);
		}
	}


	return 0;
}