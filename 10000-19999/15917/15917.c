// 15917 노솔브 방지문제야!!
// https://www.acmicpc.net/problem/15917
#include <stdio.h>

int main(){
	int T, a;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%d", &a);
		if ((a & (-a)) == a){
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}