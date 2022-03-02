// 15953 상금 헌터
// https://www.acmicpc.net/problem/15953
#include <stdio.h>

int kakao2017(int rank){
	if (rank == 0){return 0;}
	if (rank == 1){return 5000000;}
	if (rank <= 3){return 3000000;}
	if (rank <= 6){return 2000000;}
	if (rank <= 10){return 500000;}
	if (rank <= 15){return 300000;}
	if (rank <= 21){return 100000;}
	return 0;
}

int kakao2018(int rank){
	if (rank == 0 || rank >= 32){return 0;}
	int money = 5120000;
	while (rank > 1){
		money /= 2;
		rank /= 2;
	}
	return money;
}

int main(){
	int T, a, b;
	scanf("%d", &T);
	while (T-- > 0){
		scanf("%d %d", &a, &b);
		printf("%d\n", kakao2017(a) + kakao2018(b));
	}
}