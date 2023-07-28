#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<list<int>> graph(n + 1, list<int>());
	vector<int> degree(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_front(b);
		degree[b]++;
	}

	queue<int> q;
	vector<int> ans;
	for (int i = 1; i < n + 1; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			ans.push_back(i);
		}
	}


	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for(auto temp : graph[now])
		{
			degree[temp]--;
			if (degree[temp] == 0)
			{
				q.push(temp);
				ans.push_back(temp);
			}
		}
	}

	for(auto a : ans) 
	{
		cout << a << " ";
	}

	return 0;
}