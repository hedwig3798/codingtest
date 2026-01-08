#include <bits/stdc++.h>
#include <unordered_set>

#define MOD 1'000

long long N, B;

int matrix[50][5][5] = { 0, };

bool isCalculate[50] = { 0, };

int ans[5][5] = { 0, };

void PowMatirx()
{
	for (int l = 1; l < 50; l++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					matrix[l][i][j] += (matrix[l - 1][i][k] * matrix[l - 1][k][j]);
					matrix[l][i][j] %= MOD;
				}
			}
		}
	}

}



int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		ans[i][i] = 1;
		for (int j = 0; j < N; j++)
		{
			std::cin >> matrix[0][i][j];
		}
	}


	isCalculate[0] = true;

	PowMatirx();

	int ind = 0;
	while (0 < B)
	{
		if (0 < (B & 1))
		{
			int temp[5][5] = { 0, };
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					temp[i][j] = ans[i][j];
					ans[i][j] = 0;
				}
			}


			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < N; k++)
					{
						ans[i][j] += (temp[i][k] * matrix[ind][k][j]);
						ans[i][j] %= MOD;
					}
				}
			}
		}

		ind++;
		B = B >> 1;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << ans[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}