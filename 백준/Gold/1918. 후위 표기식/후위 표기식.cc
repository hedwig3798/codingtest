#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string fix;
	cin >> fix;

	stack<char>s;

	for (auto f : fix) {
		if (f == '(') {
			s.push(f);
		}
		else if (f == '/' || f == '*') {
			if (s.empty() || s.top() == '(' || s.top() == '+' || s.top() == '-') {
				s.push(f);
			}
			else {
				for (; !(s.empty() || s.top() == '(' || s.top() == '+' || s.top() == '-');) {
					cout << s.top();
					s.pop();
				}
				s.push(f);
			}
		}
		else if (f == '+' || f == '-') {
			if (s.empty() || s.top() == '(') {
				s.push(f);
			}
			else {
				for (; !(s.empty() || s.top() == '(');) {
					cout << s.top();
					s.pop();
				}
				s.push(f);
			}
		}
		else if (f == ')') {
			for (; !(s.empty() || s.top() == '(');) {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << f;
		}
	}
	
	for (; !s.empty();) {
		cout << s.top();
		s.pop();
	}

	return 0;
} 