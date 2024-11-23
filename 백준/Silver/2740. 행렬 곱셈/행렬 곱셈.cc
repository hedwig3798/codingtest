#include <bits/stdc++.h>
#pragma warning(disable: E0266)
#define le9 1'000'000'000
using namespace std;

int N, M, K;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	vector<vector<int>> A (N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	vector<vector<int>> B(M, vector<int>(K));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}

	vector<vector<int>> ans(N, vector<int>(K));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				ans[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (auto& i : ans)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
}