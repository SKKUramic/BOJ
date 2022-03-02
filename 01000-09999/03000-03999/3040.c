// 3040 백설 공주와 일곱 난쟁이
// https://www.acmicpc.net/problem/3040
#include <stdio.h>

int main(){
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int a = 0; a < 9; a++){
		for (int b = 0; b < 9; b++){
			if (a == b){continue;}
			if (sum - arr[a] - arr[b] == 100){
				for (int k = 0; k < 9; k++){
					if (k == a || k == b){continue;}
					printf("%d\n", arr[k]);
				}
				return 0;
			}
		}
	}
}