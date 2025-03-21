#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int K;

int rawData[1025] = { 0, };
int tree[1025] = { 0, };

queue<int> q;

void TreeItr(int _start, int _end, int _now)
{
	if (_end <= _start)
	{
		return;
	}
	int mid = (_start + _end) / 2;
	tree[_now * 2] = rawData[(_start + mid - 1) / 2];
	tree[_now * 2 + 1] = rawData[(_end + mid + 1) / 2];

	TreeItr(_start, mid - 1, _now * 2);
	TreeItr(mid + 1, _end, _now * 2 + 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> K;
	for (int i = 1; i < (1 << K); i++)
	{
		cin >> rawData[i];
	}

	q.push((1 << K) / 2);

	tree[1] = rawData[(1 << K) / 2];
	TreeItr(1, (1 << K) - 1, 1);


	int level = 1;
	for (int i = 1; i < (1 << K); i++)
	{
		cout << tree[i];
		if (i == (1 << level) -1)
		{
			cout << "\n";
			level++;
		}
		else
		{
			cout << " ";
		}
	}

	return 0;
}