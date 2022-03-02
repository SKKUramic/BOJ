// 14445 케이크(?) 자르기
// https://www.acmicpc.net/problem/14445
#include <stdio.h>

int main(){
	// 옆면의 생크림도 분배 대상이라서 케이크를 자르는 직선은 모두 한 점을 지나야 한다
	long long n;
	scanf("%lld", &n);
	if (n == 1){printf("0");}
	else {
		printf("%lld", (n + 1) / 2);
		// 한 번 자를 때마다 케이크 조각 수는 2씩 더해진다(최초 제외)
		// n이 짝수라면, 그냥 n을 2로 나누면 된다
		// n이 홀수라면, (n + 1)명에게 나눠준다고 생각하고 (n + 1)/2만큼 자른 후, 2조각을 합쳐 한 명에게 주면 된다
	}
}