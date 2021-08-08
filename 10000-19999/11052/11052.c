// 11052 카드 구매하기
// https://www.acmicpc.net/problem/11052
#include <stdio.h>

int card_pack[1001] = {0, }; // 카드 idx개가 들어간 카드팩 비용
int cost[1001] = {0, }; // 카드 idx개만큼 사기 위한 최대 비용

int main(){
	int N;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++){
		scanf("%d", &card_pack[n]);
	}
	for (int n = 1; n <= N; n++){
		for (int c = 1; c <= N; c++){
			if (c >= n && cost[c] < cost[c - n] + card_pack[n]){
				cost[c] = cost[c - n] + card_pack[n]; // c개 사는데 드는 최대 비용 < c-n개 사는데 드는 최대 비용 + n개 카드팩 가격이면 갱신
			}
		}
	}
	printf("%d", cost[N]);
}