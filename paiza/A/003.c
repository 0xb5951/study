#include <stdio.h>
#include <stdlib.h>

// 白は１、黒は-1とし、置かれたボードの周りを探索する。自身に-1をかけたものなら、そこにマイナスをかける。
// 自分と同じ符号か、範囲外に行ったら終了。

int board[9][9] = {};
int dx[9] = {0,0,1,1,1,0,-1,-1,-1};
int dy[9] = {0,1,1,0,-1,-1,-1,0,1};

int start_c, start_r;


void count(){
    int i,j;
    int cb = 0, cw = 0;

    for(i = 1; i < 9; i++){
        for(j = 1; j < 9;j++){
            if(board[i][j] == 1) cw++;
            if(board[i][j] == -1) cb++;
        }
    }

    // printf("%d%d", cb,cw);

    if(cw > cb) printf("%02d-%02d The white won!", cb, cw);
    if(cw < cb) printf("%02d-%02d The black won!", cb, cw);
}

void change_board(int vect, int end_c, int end_r){

    int sub_r,sub_c;
    sub_r = abs(start_r - end_r);
    sub_c = abs(start_c - end_c);

    if(vect == 1) for(int i = 0; i < sub_c; i++) board[start_c+(-1*i)][start_r] *= -1;
    if(vect == 3) for(int i = 0; i < sub_r; i++) board[start_c][start_r+i] *= -1;
    if(vect == 5) for(int i = 0; i < sub_c; i++) board[start_c+i][start_r] *= -1;
    if(vect == 7) for(int i = 0; i < sub_r; i++) board[start_c][start_r+(-1*i)] *= -1;

    if(vect == 2) for(int i = 0; i < sub_r; i++) board[start_c+i][start_r+i] *= -1;
    if(vect == 6) for(int i = 0; i < sub_r; i--) board[start_c+(-1*i)][start_c+(-1*i)] *= -1;


    // printf("1");

    if(vect == 4) for(int i = 0; i < sub_r; i++) board[start_c+i][start_r+(-1*i)] *= -1;
    if(vect == 8) for(int i = 0; i < sub_r; i++) board[start_c+(-1*i)][start_r+i] *= -1;

    return;
}

void cal_board(int vect, int c, int r, int sc){
    int i;
    if(board[c+dy[vect]][r+dx[vect]] == 0 ||
      c+dy[vect] < 1 || c+dy[vect] > 8 ||
      r+dx[vect] < 1 || r+dx[vect] > 8) return;


    if(vect == 0){
        for(i = 1; i <= 8; i++){
            if(board[c][r] == (-1*board[c+dy[i]][r+dy[i]])) cal_board(i, c+dy[i], r+dx[i], sc);
        }
    }

    if(board[c+dy[vect]][r+dx[vect]] == sc) change_board(vect, c+dy[vect], r+dx[vect]);

    cal_board(vect, c+dy[vect], r+dx[vect], sc);

}

void put_board(char color, int c, int r){
    if(color == 'B') board[c][r] = -1;
    if(color == 'W') board[c][r] = 1;

    start_c = c;
    start_r = r;

    cal_board(0, c, r, board[c][r]);
}

int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！

    int n;
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        int r,c;
        char color;
        scanf("%c%d%d", &color, &c, &r);
        put_board(color, c, r);
    }

    // for(i = 1; i <= 8; i++){
    //     for(j = 1; j <= 8; j++){
    //         printf("%d ", board[i][j]);
    //     }
    //     printf("\n");
    // }

    count();

    return 0;
}
