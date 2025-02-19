#include <bits/stdc++.h>

#define le9 1'000'000'000
using namespace std;

struct food
{
	int protine;
	int fat;
	int rice;
	int vi;
	int price;
};

vector<food> foods;
int N;

int totalPrice;
int ans = le9;
int chooseFlag = 0;
int tempChooseFlag = 0;

int mp, mf, ms, mv;
int p, f, s, v;

bool CheckNutr()
{
	if (p >= mp && f >= mf && s >= ms && v >= mv)
	{
		return true;
	}
	return false;
}

void DFS(int _now)
{
	if (_now >= N)
	{
		return;
	}

	food cf = foods[_now];

	p += cf.protine;
	f += cf.fat;
	s += cf.rice;
	v += cf.vi;
	totalPrice += cf.price;
	tempChooseFlag |= 1 << (_now);

	if (CheckNutr())
	{
		if (totalPrice < ans)
		{
			ans = totalPrice;
			chooseFlag = tempChooseFlag;
		}
	}
	else
	{
		DFS(_now + 1);
	}

	p -= cf.protine;
	f -= cf.fat;
	s -= cf.rice;
	v -= cf.vi;
	totalPrice -= cf.price;
	tempChooseFlag &= ~(1 << (_now));

	DFS(_now + 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	foods.resize(N);

	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < N; i++)
	{
		int tp, tf, ts, tv, tpr;
		cin >> tp >> tf >> ts >> tv >> tpr;
		foods[i] = { tp, tf, ts, tv, tpr };
	}

	DFS(0);

	if (chooseFlag == 0)
	{
		cout << -1;
		return 0;
	}

	cout << ans << '\n';
	for (int i = 0; i < N; i++)
	{
		if ((chooseFlag >> i) & 1)
		{
			cout << i + 1 << ' ';
		}
	}


	return 0;
}