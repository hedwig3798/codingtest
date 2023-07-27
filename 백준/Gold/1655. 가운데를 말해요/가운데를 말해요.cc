#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, less<int>> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (maxq.size() <= minq.size()) 
		{
			maxq.push(num);
		}
		else
		{
			minq.push(num);
		}


		if (!(maxq.empty() || minq.empty()) && maxq.top() > minq.top()) 
		{
			int aq = maxq.top();
			maxq.pop();
			
			int iq = minq.top();
			minq.pop();

			maxq.push(iq);
			minq.push(aq);
		}

		cout << maxq.top() << "\n";

	}

	return 0;
}