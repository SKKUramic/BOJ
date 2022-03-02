// 17419 비트가 넘쳐흘러
// https://www.acmicpc.net/problem/17419
#include <stdio.h>
// K = K-(K&((~K)+1))
// ~K + 1 = -K, K & -K = K을 이진수로 나타났을 때, 비트가 켜진 가장 아래 자리 수
// 즉 K-(K&((~K)+1))은 K의 맨 오른쪽 1비트를 0비트로 바꾸는 것이다

char K[1000001];

int main(){
	int N, one_count = 0;
	scanf("%d", &N);
	scanf("%s", K);
	for (int i = 0; i < N; i++){
		if (K[i] == '1'){one_count++;}
	}
	printf("%d", one_count);
}