// 18185 라면 사기 (Small)
// https://www.acmicpc.net/problem/18185
// 게시판을 읽어보는 게 좋긴 하군요
#include <stdio.h>

int ramen[10010] = {0, };
int N;
long long cost = 0;

int ret_3min(int a, int b, int c){
	if (a < b){
		if (a < c) {return a;}
		else {return c;}
	}
	else {
		if (b < c) {return b;}
		else {return c;}
	}
}

int ret_2min(int a, int b){
	if (a < b){return a;}
	else {return b;}
}

int main(){
	int two_buy, three_buy;
	scanf("%d", &N);
	for (int n = 0; n < N; n++){
		scanf("%d", &ramen[n]);
	}
	for (int n = 0; n < N; n++){ // 현재의 공장에서 얼마나 살지 곧바로 결정한다
		if (ramen[n] <= 0){continue;} // 이걸 통과하면 일단 ramen[n] > 0을 만족한다
		if (ramen[n + 1] > ramen[n + 2]){ 
			// https://www.acmicpc.net/board/view/44176에서 나온 예외 처리를 위한 if 구문
			// 일반적인 과정으로 진행하면 ramen[n + 1] ~ ramen[n + 3]으로 3개 묶음을 만들 때
			// n + 1번째 공장에 ramen[n + 1] - ramen[n + 2]개의 남은 라면이 전부 낱개로 구매되는데, 이를 방지한다
			// 2개 묶음을 2개 사는 것과 1개와 3개 묶음을 사는 가격의 합이 서로 같기 때문에 가능하다
			two_buy = ret_2min(ramen[n], ramen[n + 1] - ramen[n + 2]);
			cost += 5 * two_buy; // ramen[n + 2]가 0이라면 비용 계산은 여기까지다
			ramen[n] -= two_buy;
			ramen[n + 1] -= two_buy;
			three_buy = ret_3min(ramen[n], ramen[n + 1], ramen[n + 2]);
			cost += 7 * three_buy;
			ramen[n] -= three_buy;
			ramen[n + 1] -= three_buy;
			ramen[n + 2] -= three_buy;
		}
		else {
			// 일반적인 과정, 3개 묶음을 산 후, 2개 묶음을 산 후, 낱개로 산다
			three_buy = ret_3min(ramen[n], ramen[n + 1], ramen[n + 2]);
			cost += 7 * three_buy;
			ramen[n] -= three_buy;
			ramen[n + 1] -= three_buy;
			ramen[n + 2] -= three_buy;
			two_buy = ret_2min(ramen[n], ramen[n + 1]);
			cost += 5 * two_buy;
			ramen[n] -= two_buy;
			ramen[n + 1] -= two_buy;
		}
		cost += 3 * ramen[n]; // 낱개 구매, 이후 더이상 ramen[n]의 값을 참조하지 않는다
	}
	printf("%d", cost);
}