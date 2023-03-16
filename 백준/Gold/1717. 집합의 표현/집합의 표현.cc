#include <bits/stdc++.h>
using namespace std;


int union_find[1000001];


int find_parent(int x) {
	if (union_find[x] == x) {
		return x;
	}
	else {
		return union_find[x] = find_parent(union_find[x]);
	}
	
}

void add_union(int x, int y) {
	int px = find_parent(x);
	int py = find_parent(y);
	if (px == py)
		return;

	if (px > py) 
		union_find[px] = py;
	else
		union_find[py] = px;
	
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	

	for (int i = 0; i < n + 1; i++) {
		union_find[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int p, a, b;
		cin >> p >> a >> b;

		if (p == 0){
			add_union(a, b);
		}
		else if (p == 1) {
			if (find_parent(a) == find_parent(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}


	return 0;
} 