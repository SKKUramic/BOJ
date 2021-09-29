// 19944 뉴비의 기준은 뭘까?
// https://www.acmicpc.net/problem/19944
#include <stdio.h>

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	if (M == 1 || M == 2){
		printf("NEWBIE!");
	}
	else if (N >= M){
		printf("OLDBIE!");
	}
	else {
		printf("TLE!");
	}
}