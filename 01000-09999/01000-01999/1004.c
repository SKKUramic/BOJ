// 1004 어린 왕자
#include <stdio.h>

int circle[50][3]; // cx, cy, r
int in_circle[50][2]; // start in circle, end in circle, if in -1 & if out 1

void init(){
    for (int i = 0; i < 50; i++){
        circle[i][0] = 0;
        circle[i][1] = 0;
        circle[i][2] = 0;
        in_circle[i][0] = 0;
        in_circle[i][1] = 0;
    }
    return;
}

int main(){
    int test, n, count;
    int x1, y1, x2, y2;
    scanf("%d", &test);
    for (int i = 0; i < test; i++){
        init();
        count = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for (int a = 0; a < n; a++){
            scanf("%d %d %d", &circle[a][0], &circle[a][1], &circle[a][2]);
            if ( (circle[a][0] - x1) * (circle[a][0] - x1) + (circle[a][1] - y1) * (circle[a][1] - y1) < circle[a][2] * circle[a][2] ){
                in_circle[a][0] = -1;
            }
            else {
                in_circle[a][0] = 1;
            }
            if ( (circle[a][0] - x2) * (circle[a][0] - x2) + (circle[a][1] - y2) * (circle[a][1] - y2) < circle[a][2] * circle[a][2] ){
                in_circle[a][1] = -1;
            }
            else {
                in_circle[a][1] = 1;
            }
        }
        for (int b = 0; b < n; b++){
            if (in_circle[b][0] != in_circle[b][1]){
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}