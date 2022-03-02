// 11653 소인수분해
#include <stdio.h>

int main(){
	int N, index = 0;
	int arr[100] = {0, };
	scanf("%d", &N);
	if (N == 1){return 0;}
	else {
		for (int i = 2; i <= N; i++){
			while (N % i == 0){
				arr[index++] = i;
				N /= i;
			}
			if (N == 1){break;}
		}
		for (int i = 0; i < index; i++){
			printf("%d\n", arr[i]);
		}
	}
}