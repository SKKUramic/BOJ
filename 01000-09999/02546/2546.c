// 2546 경제학과 정원영
// https://www.acmicpc.net/problem/2546
#include <stdio.h>

int arr1[200001];

int main(){
	long long TC, N, M, sum1, sum2, ans, num;
	scanf("%lld", &TC);
	while (TC-- > 0){
		scanf("%lld %lld", &N, &M);
		sum1 = 0; sum2 = 0; ans = 0;
		for (int n = 0; n < N; n++){
			scanf("%lld", &arr1[n]);
			sum1 += arr1[n];
		}
		for (int m = 0; m < M; m++){
			scanf("%lld", &num);
			sum2 += num;
		}
		for (int i = 0; i < N; i++){
			if (arr1[i] * N < sum1 && arr1[i] * M > sum2){ans++;}
		}
		printf("%lld\n", ans);
	}
}