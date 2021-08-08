// 1977 완전제곱수
// https://www.acmicpc.net/problem/1977
#include <stdio.h>

int main(){
	int A, B, min = -1, sum = 0;
	scanf("%d %d", &A, &B);
	for (int i = 1; i * i <= A || i * i <= B; i++){
		if (i * i < A && i * i < B){
			continue;
		}
		else {
			if (min == -1){min = i * i;}
			sum += i * i;
		}
	}
	if (min == -1){printf("%d", min);}
	else {printf("%d\n%d", sum, min);}
}