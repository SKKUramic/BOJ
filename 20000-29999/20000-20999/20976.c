// 20976 2 番目に大きい整数 (The Second Largest Integer) 
#include <stdio.h>

int main(){
	int num[3], temp;
	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			if (num[j] > num[j + 1]){
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	printf("%d", num[1]);
}