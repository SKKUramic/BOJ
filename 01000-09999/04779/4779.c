// 4779 칸토어 집합
// https://www.acmicpc.net/problem/4779
#include <stdio.h>

void Cantor(int length){
	if (length == 1){printf("-");}
	else {
		Cantor(length / 3);
		for (int i = 0; i < length / 3; i++){printf(" ");}
		Cantor(length / 3);
	}
}

int main(){
	int length, N;
	while (scanf("%d", &length) != EOF){
		N = 1;
		for (int i = 0; i < length; i++){N *= 3;}
		Cantor(N);
		printf("\n");
	}
}