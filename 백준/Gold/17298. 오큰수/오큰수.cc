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

	stack<int> result;
	stack<int> output;
	stack<int> data;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		data.push(input);
	}

	while (!data.empty())
	{
		int num = data.top();
		data.pop();

		if (result.empty()) 
		{
			result.push(num);
			output.push(-1);
		}
		else
		{
			if (num < result.top()) 
			{
				output.push(result.top());
				result.push(num);
			}
			else
			{
				while (!result.empty() && num >= result.top())
				{
					result.pop();
				}

				if (result.empty()) 
				{
					result.push(num);
					output.push(-1);
				}
				else
				{
					output.push(result.top());
					result.push(num);
				}
			}
		}
	}

	while (!output.empty())
	{
		cout << output.top() << " ";
		output.pop();
	}

}