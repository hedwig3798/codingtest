#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int N, M, K;

struct Area
{
	int jungle = 0;
	int ocean = 0;
	int ice = 0;

	Area operator +(const Area& _other)
	{
		Area result;
		result.jungle = this->jungle + _other.jungle;
		result.ocean = this->ocean + _other.ocean;
		result.ice = this->ice + _other.ice;
		return result;
	}

	Area operator -(const Area& _other)
	{
		Area result;
		result.jungle = this->jungle - _other.jungle;
		result.ocean = this->ocean - _other.ocean;
		result.ice = this->ice - _other.ice;
		return result;
	}
};

std::vector<std::string> map;

std::vector<std::vector<Area>> dp;

void PrintArea(const Area& _area)
{
	std::cout << _area.jungle << " " << _area.ocean << " " << _area.ice << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;
	std::cin >> K;

	map.resize(N);
	dp = std::vector<std::vector<Area>>(N, std::vector<Area>(M));
	for (int i = 0; i < N ; i++)
	{
		std::cin >> map[i];
	}

	

	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < M ; j++)
		{
			Area temp;
			if (i > 0)
			{
				temp = temp + dp[i - 1][j];
			}
			if (j > 0)
			{
				temp = temp + dp[i][j - 1];
			}

			if (j > 0 && i > 0)
			{
				temp = temp -dp[i - 1][j - 1];
			}

			switch (map[i][j])
			{
			case 'J':
				temp.jungle++;
				break;
			case 'I':
				temp.ice++;
				break;
			case 'O':
				temp.ocean++;
				break;
			default:
				break;
			}
			dp[i][j] = temp;
		}
	}

	for (int i = 0; i < K ; i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		Area total = dp[c - 1][d - 1];
		if (a > 1 && b > 1)
		{
			Area left = dp[c - 1][b - 2];
			Area top = dp[a - 2][d - 1];
			Area rest = dp[a - 2][b - 2];
			total = total - left - top + rest;
		}
		else if (a > 1 && b == 1)
		{
			Area top = dp[a - 2][d - 1];
			total = total - top;
		}
		else if (a == 1 && b > 1)
		{
			Area left = dp[c - 1][b - 2];
			total = total - left;
		}
		else if (a == 1 && b == 1)
		{

		}
		PrintArea(total);
	}

	return 0;
}