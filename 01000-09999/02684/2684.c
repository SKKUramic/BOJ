// 2684 동전 게임
// https://www.acmicpc.net/problem/2684
#include <stdio.h>

int three_coin[8];

int main(){
	int T, coin;
	char coin_arr[41];
	scanf("%d", &T);
	while (T-- > 0){
		for (int i = 0; i < 8; i++){three_coin[i] = 0;}
		coin = 0;
		scanf("%s", coin_arr);
		for (int i = 0; i < 40; i++){
			coin = (coin * 2) % 8;
			if (coin_arr[i] == 'H'){
				coin += 1;
			}
			if (i >= 2){
				three_coin[coin]++;
			}
		}
		for (int i = 0; i < 8; i++){
			printf("%d ", three_coin[i]);
		}
		printf("\n");
	}
}