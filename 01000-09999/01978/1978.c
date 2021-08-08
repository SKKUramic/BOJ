// 1978 소수 찾기
#include <stdio.h>

int main(){
	int test, num, flags = 0, answer = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d", &num);
		for (int k = 2; k <= num; k++){
			if (num % k == 0){
				flags++;
			}
		}
		if (flags == 1){
			answer++;
		}
		flags = 0;
	}
	printf("%d", answer);
}