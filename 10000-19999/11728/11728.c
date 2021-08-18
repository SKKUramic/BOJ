// 11728 배열 합치기
// https://www.acmicpc.net/problem/11728
#include <stdio.h>

int arr[2000001];
int A[1000001], B[1000001];

int main(){
	int num, N, M, idx = 0;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++){
		scanf("%d", &A[n]);
	}
	for (int m = 0; m < M; m++){
		scanf("%d", &B[m]);
	}
	int A_pointer = 0, B_pointer = 0;
	while (A_pointer != N || B_pointer != M){
		if (A_pointer == N){
			arr[idx++] = B[B_pointer++];
		}
		else if (B_pointer == M){
			arr[idx++] = A[A_pointer++];
		}
		else {
			if (A[A_pointer] < B[B_pointer]){
				arr[idx++] = A[A_pointer++];
			}
			else {
				arr[idx++] = B[B_pointer++];
			}
		}
	}
	for (int k = 0; k < N + M; k++){
		printf("%d ", arr[k]);
	}
}