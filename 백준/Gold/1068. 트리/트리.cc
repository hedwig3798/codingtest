#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> tree(n, vector<int>());
	vector<bool> isDelete(n, false);
	int root;
	for (int i = 0; i < n; i++)
	{
		int pa;
		cin >> pa;
		if (pa == -1) 
		{
			root = i;
			continue;
		}
		tree[pa].push_back(i);
	}

	int del;
	cin >> del;

	stack<int> d;
	d.push(del);

	while (!d.empty())
	{
		int now = d.top();
		d.pop();
		isDelete[now] = true;
		for(auto node : tree[now])
		{
			d.push(node);
		}
	}

	int ans = 0;
	for (int i = 0; i < tree.size(); i++)
	{
		if (isDelete[i])
		{
			continue;
		}
		bool flag = true;
		for(auto node : tree[i])
		{
			if (!isDelete[node])
			{
				flag = false;
			}
		}
		if (flag) 
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}