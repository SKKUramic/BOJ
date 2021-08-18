// 6794 What is n, Daddy?
// https://www.acmicpc.net/problem/6794
#include <stdio.h>

int main(){
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < 6; i++){
		for (int j = i; j < 6; j++){
			if (i + j == n){count++;}
		}
	}
	printf("%d", count);
}