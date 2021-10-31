// 13458 시험 감독
// https://www.acmicpc.net/problem/13458
#include <stdio.h>

long long arr[1000001];

int main(){
	long long N, B, C;
	long long ans = 0;
	scanf("%lld", &N);
	for (int n = 0; n < N; n++){
		scanf("%lld", &arr[n]);
	}
	scanf("%lld %lld", &B, &C);
	for (int n = 0; n < N; n++){
		ans += 1; // 감독관
		if (arr[n] - B > 0){ // 감독관만으로는 감당할 수 없을 때
			ans += ((arr[n] - B) / C) + ((arr[n] - B) % C != 0 ? 1 : 0);
		}
	}
	printf("%lld", ans);
}