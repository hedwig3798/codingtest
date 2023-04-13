#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	int count = 0;
	for(;b > a;) {
		count++;
		if (b % 2 == 0) {
			b /= 2;
		}
		else if (b % 10 == 1) {
			b /= 10;
		}
		else {
			break;
		}
	}
	
	if (a== b){
		cout << count + 1;
	}
	else {
		cout << -1;
	}

	return 0;
}