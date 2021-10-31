// 6359 만취한 상범
// https://www.acmicpc.net/problem/6359
#include <stdio.h>

int main(){
	int N, T;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d", &N);
		int arr[101] = {0, };
		int answer = 0;
		for (int k = 1; k <= N; k++){
			for (int p = k; p <= N; p += k){
				arr[p]++;
			}
		}
		for (int n = 1; n <= N; n++){
			if (arr[n] % 2 == 1){answer++;}
		}
		printf("%d\n", answer);
	}
}