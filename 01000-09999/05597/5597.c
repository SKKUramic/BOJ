// 5597 과제 안 내신 분..?
// https://www.acmicpc.net/problem/5597
#include <stdio.h>

int homework[31] = {0, };

int main(){
	int num;
	for (int i = 0; i < 28; i++){
		scanf("%d", &num);
		homework[num]++;
	}
	for (int i = 1; i <= 30; i++){
		if (homework[i] == 0){
			printf("%d\n", i);
		}
	}
}