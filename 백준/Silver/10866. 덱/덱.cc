#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* prev;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push_back")
		{
			int num;
			cin >> num;
			Node* temp = new Node;

			temp->value = num;
			temp->next = nullptr;
			temp->prev = nullptr;

			if (size == 0)
			{
				tail = temp;
				head = temp;
			}
			else
			{
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}


			size++;
		}
		else if (s == "push_front")
		{
			int num;
			cin >> num;
			Node* temp = new Node;

			temp->value = num;
			temp->next = nullptr;
			temp->prev = nullptr;

			if (size == 0)
			{
				tail = temp;
				head = temp;
			}
			else
			{
				head->prev = temp;
				temp->next = head;
				head = temp;
			}


			size++;
		}
		else if (s == "pop_front")
		{
			if (size != 0)
			{
				cout << head->value << "\n";
				Node* temp = head;
				head = head->next;
				delete temp;
				size--;
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (s == "pop_back")
		{
			if (size != 0)
			{
				cout << tail->value << "\n";
				Node* temp = tail;
				tail = tail->prev;
				delete temp;
				size--;
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (s == "size")
		{
			cout << size << "\n";
		}
		else if (s == "empty")
		{
			if (size == 0)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (s == "front")
		{
			if (size == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << head->value << "\n";
			}
		}
		else if (s == "back")
		{
			if (size == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << tail->value << "\n";
			}
		}
	}
}