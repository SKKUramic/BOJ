// 3003 킹, 퀸, 룩, 비숍, 나이트, 폰
#include <stdio.h>

int main(){
	int chess[6]; // king1 queen1 rook2 bishop2 knight2 pawn8
	scanf("%d %d %d %d %d %d", &chess[0], &chess[1], &chess[2], &chess[3], &chess[4], &chess[5]);
	printf("%d %d %d %d %d %d", 1 - chess[0], 1 - chess[1], 2 - chess[2], 2 - chess[3], 2 - chess[4], 8 - chess[5]);
}