#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>

#define INF 1e9
#define MOD = 1'000'000'000;
typedef long long ll;

using namespace std;

int N, M;

vector<vector<char>> maze;
vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> points;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int MazeBFS(const pair<int, int>& _start, const pair<int, int>& _end)
{
	queue<pair<int, int>> q;
	q.push(_start);

	vector<vector<int>> isVisit(N, vector<int>(N, -1));
	isVisit[_start.first][_start.second] = 0;

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();
		auto x = now.first;
		auto y = now.second;

		for (int i = 0; i < 4; i++)
		{
			auto nx = x + dx[i];
			auto ny = y + dy[i];

			if (maze[nx][ny] == '1' || isVisit[nx][ny] != -1)
				continue;

			if (nx == _end.first && ny == _end.second)
				return isVisit[x][y] + 1;

			isVisit[nx][ny] = isVisit[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	maze = vector<vector<char>>(N, vector<char>(N));

	graph = vector<vector<pair<int, int>>>(M + 1);

	pair<int, int> sPoint;
	points.push_back({ 1, 1 });
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char input;
			cin >> input;
			maze[i][j] = input;

			if (input == 'S')
				points[0] = { i,j };
			else if (input == 'K')
				points.push_back({ i, j });
		}
	}

	for (int i = 0; i < points.size(); i++)
	{
		for (int j = i + 1; j < points.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			int dis = MazeBFS(points[i], points[j]);
			if (dis == -1)
			{
				cout << -1;
				return 0;
			}
			graph[i].push_back({ j, dis });
			graph[j].push_back({ i, dis });
		}

	}

	priority_queue<std::pair<int, int>> pq;

	for (auto& n : graph[0])
	{
		pq.push({ -n.second, n.first });
	}

	vector<bool> isVisit(M + 1, false);
	isVisit[0] = true;

	int ans = 0;

	while (!pq.empty())
	{
		auto now = pq.top();
		pq.pop();

		int dis = -now.first;
		int curr = now.second;

		if (isVisit[curr])
		{
			continue;
		}

		isVisit[curr] = true;
		ans += dis;
		for (auto& next : graph[curr])
		{
			int nDis = next.second;
			int nNode = next.first;
			if (!isVisit[nNode])
			{
				pq.push({ -nDis, nNode });
			}
		}
	}

	cout << ans;

	return 0;
}