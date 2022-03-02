// 4101 크냐?
// https://www.acmicpc.net/problem/4101
#include <stdio.h>

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	while (A != 0 || B != 0){
		if (A > B){printf("Yes\n");}
		else {printf("No\n");}
		scanf("%d %d", &A, &B);
	}
}