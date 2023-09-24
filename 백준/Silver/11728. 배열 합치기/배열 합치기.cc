#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	long long N, M;
	cin >> N >> M;
	vector<long long> result;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		result.push_back(num);
	}

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		result.push_back(num);
	}
	
	sort(result.begin(), result.end());

	for (auto num : result)
	{
		cout << num << " ";
	}
	return 0;
}