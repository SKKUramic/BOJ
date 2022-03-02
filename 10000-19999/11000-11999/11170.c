// 11170 0의 개수
// https://www.acmicpc.net/problem/11170
#include <stdio.h>

int zero_count[1000001] = {0, };

int main(){
	int temp, TC, A, B, ans;
	for (int i = 0; i <= 1000000; i++){
		temp = i;
		while (1){
			if (temp % 10 == 0){zero_count[i]++;}
			temp /= 10;
			if (temp == 0){break;}
		}
	}
	scanf("%d", &TC);
	while (TC-- > 0){
		ans = 0;
		scanf("%d %d", &A, &B);
		for (int i = A; i <= B; i++){
			ans += zero_count[i];
		}
		printf("%d\n", ans);
	}
}