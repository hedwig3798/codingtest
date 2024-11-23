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

vector<int> isPrime;

vector<int> ans;

int T;

bool IsPrime(int _num)
{
	if (isPrime[_num] == 1)
	{
		return true;
	}
	else if (isPrime[_num] == 0)
	{
		return false;
	}

	for (int i = 2; i * i <= _num; i++)
	{
		if (_num % i == 0)
		{
			isPrime[_num] = 0;
			return false;
		}
	}

	isPrime[_num] = 1;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	isPrime = vector<int>(10000, -1);

	for (int i = 1000; i <= 9999; i++)
	{
		IsPrime(i);
	}

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		bool findAns = false;
		int start, end;
		cin >> start >> end;

		vector<int> isVisit(10000, -1);

		queue<int> q;
		q.push(start);
		isVisit[start] = 0;

		while (!q.empty() && !findAns)
		{
			int curr = q.front();
			q.pop();

			if (curr == end)
			{
				ans.push_back(isVisit[end]);
				findAns = true;
				break;
			}

			int temp[4] = {};

			temp[3] = (curr % 10);
			temp[2] = ((curr % 100) - temp[3]) / 10;
			temp[1] = ((curr % 1000) - temp[3] - (temp[2] * 10)) / 100;
			temp[0] = ((curr % 10000) - temp[3] - (temp[2] * 10) - temp[1] * 100) / 1000;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					int next = 0;

					if (i != 0)
						next += temp[0] * 1000;
					if (i != 1)
						next += temp[1] * 100;
					if (i != 2)
						next += temp[2] * 10;
					if (i != 3)
						next += temp[3] * 1;
					switch (i)
					{
					case 0:
						next += j * 1000;
						break;
					case 1:
						next += j * 100;
						break;
					case 2:
						next += j * 10;
						break;
					case 3:
						next += j * 1;
						break;
					default:
						break;
					}

					if (next == end)
					{
						ans.push_back(isVisit[curr] + 1);
						findAns = true;

						break;
					}

					if (next < 1000 || next > 9999 || !IsPrime(next) || isVisit[next] != -1)
						continue;

					isVisit[next] = isVisit[curr] + 1;
					q.push(next);
				}
			}
		}
		if (!findAns)
		{
			ans.push_back(-1);
		}
	}

	for (auto& a : ans)
	{
		if (a == -1)
		{
			cout << "Impossible\n";
			continue;
		}

		cout << a << '\n';
	}

	return 0;
}