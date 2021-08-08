// 10830 행렬 제곱
#include <stdio.h>

unsigned long long int answer[5][5] = {0, };
unsigned long long int arr[5][5] = {0, };

void print_matrix(unsigned long long int X[5][5], int N){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%lld ", X[i][j]);
		}
		printf("\n");
	}
	//printf("print_matrix ended\n\n");
	return;
}

void Multi_matrix(unsigned long long int A[5][5], unsigned long long int B[5][5], int N){
	unsigned long long int temp[5][5] = {0, };
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				temp[i][j] += A[i][k] * B[k][j];
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			A[i][j] = temp[i][j];
		}
	}
	return;
}

int main(){
	int N;
	unsigned long long int B, temp = 1;
	scanf("%d %lld", &N, &B);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%lld", &arr[i][j]);
			if (i == j){
				answer[i][j] = 1;
			}
		}
	}
	while (B > 0){
		if (B % 2 == 1){
			Multi_matrix(answer, arr, N);
		}
		Multi_matrix(arr, arr, N);
		//printf("print_arr\n");
		//print_matrix(arr, N);
		//printf("print_answer\n");
		//print_matrix(answer, N);
		B /= 2;
	}
	print_matrix(answer, N);
}