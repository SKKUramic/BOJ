// 9550 아이들은 사탕을 좋아해
// https://www.acmicpc.net/problem/9550
#include <stdio.h>

int main(){
	int TC, N, K, eat, candy;
	scanf("%d", &TC);
	while (TC-- > 0){
		eat = 0;
		scanf("%d %d", &N, &K);
		for (int n = 0; n < N; n++){
			scanf("%d", &candy);
			eat += (candy / K);
		}
		printf("%d\n", eat);
	}
}