#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int total = 0;
	int number = 666;
	while (total < N)
	{
		int temp = number;
		bool find = false;

		while (temp >= 666)
		{
			if (temp % 1000 == 666)
			{
				total++;
				find = true;
				break;
			}
			temp /= 10;
		}
		number++;
	}

	cout << number - 1;
}