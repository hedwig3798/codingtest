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

int N;

vector<int> A;
vector<int> B;
vector<int> BIN;
vector<int> AIN;
vector<int> lis;


int UB(int _val)
{
	int start = 0;
	int end = lis.size();

	while (start < end)
	{
		int mid = (start + end) * 0.5;

		if (lis[mid] < _val)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	return end;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	A = vector<int>(N + 1);
	B = vector<int>(N + 1);
	AIN = vector<int>(N + 1);
	BIN = vector<int>(N + 1);

	for (int i = 1; i <= N ; i++)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> B[i];
		BIN[B[i]] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		AIN[i] = BIN[A[i]];
	}

	for (int i = 1; i <= N; i++)
	{
		if (lis.empty() || lis.back() <= AIN[i])
		{
			lis.push_back(AIN[i]);
		}
		else
		{
			int temp = UB(AIN[i]);
			lis[temp] = AIN[i];
		}
	}

	cout << lis.size();

	return 0;
}