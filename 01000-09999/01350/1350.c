// 1350 진짜 공간
// https://www.acmicpc.net/problem/1350
#include <stdio.h>

unsigned long long int file[1000];
unsigned long long int cluster, answer = 0;

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%lld", &file[i]);
	}
	scanf("%lld", &cluster);
	for (int i = 0; i < N; i++){
		if (file[i] != 0){
			answer += file[i] / cluster;
			if (file[i] % cluster != 0){
				answer++;
			}
		}
	}
	printf("%lld", answer * cluster);
}