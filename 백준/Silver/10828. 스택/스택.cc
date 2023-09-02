#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	vector<int> sta;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			sta.push_back(num);
		}
		else if (s == "pop")
		{
			if (sta.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << sta.back() << "\n";
				sta.pop_back();
			}
		}
		else if (s == "size")
		{
			cout << sta.size() << "\n";
		}
		else if (s == "empty")
		{
			if (sta.size() == 0)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (s == "top")
		{
			if (sta.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << sta.back() << "\n";

			}
		}
	}
}