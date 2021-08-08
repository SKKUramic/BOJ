// 10874 이교수님의 시험
#include <stdio.h>

int main(){
	int arr[10], again[100];
	int N, test_again = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 10; j++){
			scanf("%d", &arr[j]);
		}
		for (int j = 0; j < 10; j++){
			//printf("%d, %d\n", 1 + (j % 5), arr[j]);
			if (1 + (j % 5) != arr[j]){
				break;
			}
			//printf("%d, %d\n", 1 + (j % 5), i);
			if (j == 9){
				again[test_again++] = i + 1;
			}
		}
	}
	for (int k = 0; k < test_again; k++){
		printf("%d\n", again[k]);
	}
}