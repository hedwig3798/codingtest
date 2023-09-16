#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> candyMap(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> totalMap(N + 1, vector<int>(M + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int num;
			cin >> num;
			candyMap[i][j] = num;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int maxCandy = max(totalMap[i - 1][j], totalMap[i][j - 1]);
			maxCandy = max(maxCandy, totalMap[i - 1][j - 1]);
			totalMap[i][j] = maxCandy + candyMap[i][j];
		}
	}

	cout << totalMap[N][M];
}