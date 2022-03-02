// 4396 지뢰 찾기
// https://www.acmicpc.net/problem/4396
#include <stdio.h>
#include <string.h>

char mine[12][12];
char click[12][12];
char input[12];

int main(){
    int N, BOOM = 0, bomb_count;
    scanf("%d", &N);
    for (int i = 0; i <= N + 1; i++){
        click[0][i] = '.'; click[N + 1][i] = '.';
        click[i][0] = '.'; click[i][N + 1] = '.';
    }
    for (int n = 1; n <= N; n++){
        scanf("%s", input);
        for (int i = 1; i <= N; i++){
            mine[n][i] = input[i - 1];
        }
    }
    for (int n = 1; n <= N; n++){
        scanf("%s", input);
        for (int i = 1; i <= N; i++){
            click[n][i] = input[i - 1];
        }
    }
    for (int n = 1; n <= N; n++){
        for (int i = 1; i <= N; i++){
            if (mine[n][i] == '*' && click[n][i] == 'x'){
                BOOM = 1;
            }
        }
    }
    for (int n = 1; n <= N; n++){
        for (int i = 1; i <= N; i++){
            if (click[n][i] == '.'){
                if (BOOM == 1 && mine[n][i] == '*'){
                    click[n][i] = mine[n][i];
                }
            }
            else {
                if (mine[n][i] == '*'){
                    click[n][i] = '*';
                }
                else{
                    bomb_count = 0;
                    for (int a = -1; a <= 1; a++){
                        for (int b = -1; b <= 1; b++){
                            if (mine[n + a][i + b] == '*'){
                                bomb_count++;
                            }
                        }
                        click[n][i] = '0' + bomb_count;
                    }
                }
            }
        }
    }
    for (int n = 1; n <= N; n++){
        for (int i = 1; i <= N; i++){
            printf("%c", click[n][i]);
        }
        printf("\n");
    }
}