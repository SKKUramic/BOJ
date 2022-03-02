// 1975 Number Game
// https://www.acmicpc.net/problem/1975
#include <stdio.h>

int return_zerocount(int N, int d){
	int zero = 0;
	while (N > 0){
		if (N % d != 0){break;}
		zero++;
		N /= d;
	}
	return zero;
}

int main(){
	int T, num, zero_count;
	scanf("%d", &T);
	while (T-- > 0){
		zero_count = 0;
		scanf("%d", &num);
		for (int i = 2; i <= num; i++){
			zero_count += return_zerocount(num, i);
		}
		printf("%d\n", zero_count);
	}
}