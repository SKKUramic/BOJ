// 2875 대회 or 인턴
// https://www.acmicpc.net/problem/2875
#include <stdio.h>

int main(){
	int N, M, K, team = 0;
	scanf("%d %d %d", &N, &M, &K);
	while (1){
		if (N <= 1 || M <= 0){break;}
		N -= 2; M--; 
		if (N + M >= K) {team++;}
		else {break;}
	}
	printf("%d", team);
}