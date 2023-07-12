// 1987번 알파벳

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;

/*
이전의 상태를 저장하고 트리를 그려야 해서 bt로 풀어야 한다


*/

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int maxRes = 0;
const int RCMAX = 21;
bool isVisAlphabet[30];
bool isVisBoard[RCMAX][RCMAX];
int R, C;

void doDFS(int posi, int posj, int cnt, vector<string>& board) {

    for (int i = 0; i < 4; i++) {
        int cPosi = posi + dy[i];
        int cPosj = posj + dx[i];

        if (isVisBoard[cPosi][cPosj]) {
            continue;
        }
        if (cPosi < 0 || cPosi >= R || cPosj < 0 || cPosj >= C) {
            continue;
        }
        int cposAlpha = board[cPosi][cPosj] - 'A';
        if (isVisAlphabet[cposAlpha]) {
            continue;
        }

        isVisAlphabet[cposAlpha] = true;
        isVisBoard[cPosi][cPosj] = true;

        cnt++;
        maxRes = max(cnt, maxRes);
        //cout << cPosi << " / " << cPosj << " / " << cnt << "\n";

        doDFS(cPosi, cPosj, cnt, board);
		isVisAlphabet[cposAlpha] = false;
		isVisBoard[cPosi][cPosj] = false;
        cnt--;
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    vector<string> board(R);

    for (int i = 0; i < R; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++) {
            board[i] = input;
        }
    }

    for (int i = 0; i < 30; i++) {
        isVisAlphabet[i] = false;
    }

    for (int i = 0; i < RCMAX; i++) {
        for (int j = 0; j < RCMAX; j++) {
            isVisBoard[i][j] = false;
        }
    }

    isVisBoard[0][0] = true;
    int cposAlpha = board[0][0] - 'A';
    isVisAlphabet[cposAlpha] = true;

    doDFS(0, 0, 0, board);


    cout << maxRes + 1;

    return 0;
}