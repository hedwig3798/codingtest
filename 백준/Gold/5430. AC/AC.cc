#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string p;
		cin >> p;
		int n;
		cin >> n;

		deque<int> dq;
		string temp;
		cin >> temp;

		int sum = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '[')
				continue;
			else if (temp[i] == ',' || temp[i] == ']') {
				if (sum != 0)
					dq.push_back(sum);
				sum = 0;
			}
			else {
				sum = sum * 10 + (temp[i] - '0');
			}
		}

		bool reverseFlag = false;
		bool isError = false;
		for (auto com : p) {
			if (com == 'R') {
				reverseFlag = !reverseFlag;
			}
			else if (com == 'D') {
				if (dq.empty()) {
					isError = true;
					break;
				}
				if (reverseFlag) {
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}
			}
		}

		if (isError)
			cout << "error" << endl;
		else {
			cout << '[';
			if (!reverseFlag) {
				for (; dq.size() > 1;) {
					cout << dq.front() << ',';
					dq.pop_front();
				}
				if (dq.size() == 1) {
					cout << dq.front();
					dq.pop_front();
				}
			}
			else {
				for (; dq.size() > 1;) {
					cout << dq.back() << ',';
					dq.pop_back();
				}
				if (dq.size() == 1) {
					cout << dq.back();
					dq.pop_back();
				}
			}
			cout << ']';
			cout << endl;
		}
	}
	
	

	return 0;
} 