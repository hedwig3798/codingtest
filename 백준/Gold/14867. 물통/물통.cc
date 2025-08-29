#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;


int A, B, C, D;

std::map<pii, int> isVisit;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> A >> B >> C >> D;

	std::queue<pii> q;
	q.push({ 0, 0 });
	isVisit[{0, 0}] = 1;

	while (false == q.empty())
	{
		pii curr = q.front();
		q.pop();

		int ca = curr.first;
		int cb = curr.second;

		// fill A
		{
			int na = A;
			int nb = cb;
			auto mit = isVisit.find({ na, nb });
			if (isVisit.end() == mit)
			{
				q.push({ na, nb });
				isVisit[{na, nb}] = isVisit[{ca, cb}] + 1;
			}
		}
		// fill B
		{
			int na = ca;
			int nb = B;
			auto mit = isVisit.find({ na, nb });
			if (isVisit.end() == mit)
			{
				q.push({ na, nb });
				isVisit[{na, nb}] = isVisit[{ca, cb}] + 1;
			}
		}
		// empty A
		{
			int na = 0;
			int nb = cb;
			auto mit = isVisit.find({ na, nb });
			if (isVisit.end() == mit)
			{
				q.push({ na, nb });
				isVisit[{na, nb}] = isVisit[{ca, cb}] + 1;
			}
		}
		// empty B
		{
			int na = ca;
			int nb = 0;
			auto mit = isVisit.find({ na, nb });
			if (isVisit.end() == mit)
			{
				q.push({ na, nb });
				isVisit[{na, nb}] = isVisit[{ca, cb}] + 1;
			}
		}
		// A -> B
		{
			int na = 0;
			int nb = ca + cb;
			if (nb > B)
			{
				na = nb - B;
				nb = B;
			}

			auto mit = isVisit.find({ na, nb });
			if (isVisit.end() == mit)
			{
				q.push({ na, nb });
				isVisit[{na, nb}] = isVisit[{ca, cb}] + 1;
			}
		}
		// B -> A
		{
			int na = ca + cb;
			int nb = 0;
			if (na > A)
			{
				nb = na - A;
				na = A;
			}

			auto mit = isVisit.find({ na, nb });
			if (isVisit.end() == mit)
			{
				q.push({ na, nb });
				isVisit[{na, nb}] = isVisit[{ca, cb}] + 1;
			}
		}
	}

	auto mit = isVisit.find({ C, D });
	if (isVisit.end() == mit)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << mit->second - 1;
	}

	return 0;
}