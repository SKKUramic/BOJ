// 16194 카드 구매하기 2
// https://www.acmicpc.net/problem/16194
// 11052 카드 구매하기 문제의 해답 코드와 거의 동일합니다
#include <stdio.h>
#define INF 999999999

int card_pack[1001] = {0, }; // 카드 idx개가 들어간 카드팩 비용
int cost[1001]; // 카드 idx개만큼 사기 위한 최소 비용

int main(){
	int N;
	for (int i = 1; i <= 1000; i++){ // 솔직히 안 사는데 돈이 소모될 리는 없으니까
		cost[i] = INF;
	}
	scanf("%d", &N);
	for (int n = 1; n <= N; n++){
		scanf("%d", &card_pack[n]);
	}
	for (int n = 1; n <= N; n++){
		for (int c = 1; c <= N; c++){
			if (c >= n && cost[c] > cost[c - n] + card_pack[n]){
				cost[c] = cost[c - n] + card_pack[n]; // c개 사는데 드는 최대 비용 < c-n개 사는데 드는 최대 비용 + n개 카드팩 가격이면 갱신
			}
		}
	}
	printf("%d", cost[N]);
}