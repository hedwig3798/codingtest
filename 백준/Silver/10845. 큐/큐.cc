#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int value;
	Node* next;
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
		if (s == "push")
		{
			int num;
			cin >> num;
			Node* temp = new Node;

			temp->value = num;
			temp->next = nullptr;

			if (size == 0)
			{
				tail = temp;
				head = temp;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}


			size++;
		}
		else if (s == "pop")
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