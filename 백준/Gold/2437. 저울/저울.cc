#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> coinList;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		coinList.push_back(num);
	}

	sort(coinList.begin(), coinList.end());

	int result = 1;
	for (auto coin : coinList)
	{
		if (coin <= result)
		{
			result += coin;
		}
		else
		{
			break;
		}
	}
	cout << result;
	return 0;
}