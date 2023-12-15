#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <memory.h>

#define INF (int)1e9
using namespace std;

int N;

struct Node
{
	string val;
	map<string, Node*> child;
};

Node* root;

void InsertTree(vector<string>& _food)
{
	Node* temp = root;

	for (auto& f : _food)
	{
		if (temp->child.find(f) == temp->child.end())
		{
			Node* newNode = new Node();
			newNode->val = f;

			temp->child[f] = newNode;
			temp = newNode;
		}
		else
		{
			temp = temp->child[f];
		}
	}
}

void PrintTree(int _depth, Node* _now)
{
	for (int i = 0; i < _depth; i++)
	{
		cout << "--";
	}

	cout << _now->val << "\n";

	for(auto& n : _now->child) 
	{
		PrintTree(_depth + 1, n.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	root = new Node();
	root->val = "";

	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;

		vector<string> food(K);
		for (int j = 0; j < K; j++)
		{
			cin >> food[j];
		}
		InsertTree(food);
	}

	for(auto& r : root->child) 
	{
		PrintTree(0, r.second);
	}

	return 0;
}