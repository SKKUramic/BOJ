// 10448 유레카 이론
// https://www.acmicpc.net/problem/10448
#include <stdio.h>

int arr[1000];
int Eureka = 1;

int three_tri(int K){
	for (int i = 0; i < Eureka; i++){
		for (int j = 0; j < Eureka; j++){
			for (int k = 0; k < Eureka; k++){
				if (arr[i] + arr[j] + arr[k] == K){
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	int N, K;
	while(Eureka * (Eureka + 1) / 2 <= 1000){
		arr[Eureka - 1] = Eureka * (Eureka + 1) / 2;
		Eureka++;
	}
	Eureka--;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &K);
		printf("%d\n", three_tri(K));
	}
}