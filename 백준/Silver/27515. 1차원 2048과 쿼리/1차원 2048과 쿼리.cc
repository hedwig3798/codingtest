// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
숫자 개수 카운트하기
2의 배수 배열 만들기

개수 / 2 만큼 다음 배열로 올리기
1인 최종 값 출력하기
2의 몇 배수인지 카운트 바로 넣는 방법?

tmp 배열에 넣고 다시 덮어쓰기
*/

int cntK[150];

int getIdx(ll num) {
	if (num == 0) return 100;

	int ret = 0;
	while (1) {
		if (num == 1) break;
		num /= 2;
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int Q; cin >> Q;

	while (Q--) {
		char op; cin >> op;
		ll x; cin >> x;
		if (op == '+') {
			int idx = getIdx(x);
			cntK[idx]++;
		}
		else if (op == '-') {
			int idx = getIdx(x);
			cntK[idx]--;
		}
		int tmp[150];
		for (int i = 0; i < 150; i++) {
			tmp[i] = cntK[i];
		}

		for (int i = 0; i < 70; i++) {
			cntK[i + 1] += cntK[i] / 2;
		}

		int resK = -1;
		for (int i = 0; i < 70; i++) {
			if (cntK[i] >= 1) {
				resK = i;
			}
		}

		for (int i = 0; i < 150; i++) {
			cntK[i] = tmp[i];
		}

		ll res = 1ll << resK;

		if (resK == -1)
			res = 0;

		cout << res << "\n";


	}

	return 0;
}