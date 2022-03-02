// 2960 에라토스테네스의 체
// https://www.acmicpc.net/problem/2960
#include <stdio.h>

int seive[1001] = {0, };

int main(){
	int N, K, cnt = 0;
	scanf("%d %d", &N, &K);
	for (int n = 2; n <= N; n++){
		if (seive[n] == 1){continue;} // 이미 지워짐
		for (int k = n; k <= N; k += n){
			if (seive[k] == 1){continue;}
			seive[k] = 1;
			cnt++;
			if (cnt == K){
				printf("%d", k);
				return 0;
			}
		}
	}
}