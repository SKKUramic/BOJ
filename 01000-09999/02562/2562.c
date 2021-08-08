// 2562 최댓값
#include <stdio.h>

int main(int argc, char* argv[]) {
	int arr[10];
	int max = -1, index;
	for (int i = 1; i < 10; i++){
		scanf("%d", &arr[i]);
		if (max < arr[i]){
			max = arr[i];
			index = i;
		}
	}
	printf("%d\n%d", max, index);
}