// 10989 수 정렬하기 3
#include <stdio.h>

//int arr[10000001];
int count[10001] = {0, };

int main(){
	int N, index, max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &index);
		if (max < index){max = index;}
		count[index]++;
	}
	// printf("max: %d\n", max);
	for (int i = 1; i <= max; i++){
		while (count[i]){
			printf("%d\n", i);
			count[i]--;
		}
	}
}