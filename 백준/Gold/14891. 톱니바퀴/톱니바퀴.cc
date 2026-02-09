#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define TOP 0
#define RIGHT 2
#define LEFT 6

std::deque<int> gear[4];

void RotateCW(int _curr, bool _isVisit[]);
void RotateCCW(int _curr, bool _isVisit[]);

void RotateCCW(int _curr, bool _isVisit[])
{
	// 방문 처리
	if (true == _isVisit[_curr])
	{
		return;
	}

	_isVisit[_curr] = true;

	// 비교
	int cr = gear[_curr][RIGHT];
	int cl = gear[_curr][LEFT];

	// 회전
	gear[_curr].push_back(gear[_curr].front());
	gear[_curr].pop_front();

	// 왼쪽 톱니
	if (_curr > 0)
	{
		int next = _curr - 1;
		if (cl == gear[next][RIGHT])
		{
		}
		else
		{
			RotateCW(next, _isVisit);
		}
	}
	if (_curr < 3)
	{
		int next = _curr + 1;

		if (cr == gear[next][LEFT])
		{
		}
		else
		{
			RotateCW(next, _isVisit);
		}
	}
}

void RotateCW(int _curr, bool _isVisit[])
{
	// 방문 처리
	if (true == _isVisit[_curr])
	{
		return;
	}

	_isVisit[_curr] = true;

	// 비교
	int cr = gear[_curr][RIGHT];
	int cl = gear[_curr][LEFT];

	// 회전
	gear[_curr].push_front(gear[_curr].back());
	gear[_curr].pop_back();

	// 왼쪽 톱니
	if (_curr > 0)
	{
		int next = _curr - 1;
		if (cl == gear[next][RIGHT])
		{
		}
		else
		{
			RotateCCW(next, _isVisit);
		}
	}
	if (_curr < 3)
	{
		int next = _curr + 1;

		if (cr == gear[next][LEFT])
		{
		}
		else
		{
			RotateCCW(next, _isVisit);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	for (int i = 0; i < 4; ++i)
	{
		std::string s;
		std::cin >> s;
		for(auto& c : s)
		{
			gear[i].push_back(c - '0');
		}
	}

	int K;
	std::cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int a, b;
		std::cin >> a >> b;

		bool isVisit[4] = { 0, };

		if (1 == b)
		{
			RotateCW(a - 1, isVisit);
		}
		else
		{
			RotateCCW(a - 1, isVisit);
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (1 == gear[i][TOP])
		{
			ans += 1 << i;
		}
	}

	std::cout << ans;

	return 0;
}