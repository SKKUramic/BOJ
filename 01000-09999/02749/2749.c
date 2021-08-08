// 2749 피보나치 수 3
// https://www.acmicpc.net/problem/2749
// https://www.acmicpc.net/blog/view/28에서 배웠으며, 11444 피보나치 수 6의 풀이와 동일합니다.
#include <stdio.h>

long long int answer_matrix[2][2] = {{1, 0}, {0, 1}}; // 단위행렬
long long int fibonacci_matrix[2][2] = {{1, 1}, {1, 0}}; // 피보나치 행렬
long long int temp_matrix[2][2] = {{0, 0}, {0, 0}}; // 임시로 답을 계산하는 행렬

int main(){
	long long int n;
	scanf("%lld", &n);
	if (n == 1){
		printf("1");
		return 0;
	}
	while (n > 0) {
		temp_matrix[0][0] = 0; temp_matrix[0][1] = 0; temp_matrix[1][0] = 0; temp_matrix[1][1] = 0;
		if (n % 2 == 1){
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < 2; j++){
					for (int k = 0; k < 2; k++){
						temp_matrix[i][j] += answer_matrix[i][k] * fibonacci_matrix[k][j];
						temp_matrix[i][j] %= 1000000; 
					}
				}
			}
			for (int i = 0; i < 2; i++){
				for (int j = 0; j < 2; j++){
					answer_matrix[i][j] = temp_matrix[i][j];
				}
			}
		}
		temp_matrix[0][0] = 0; temp_matrix[0][1] = 0; temp_matrix[1][0] = 0; temp_matrix[1][1] = 0;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				for (int k = 0; k < 2; k++){
					temp_matrix[i][j] += fibonacci_matrix[i][k] * fibonacci_matrix[k][j];
					temp_matrix[i][j] %= 1000000; 
				}
			}
		}
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				fibonacci_matrix[i][j] = temp_matrix[i][j];
			}
		}
		n /= 2;
	}
	printf("%lld", answer_matrix[0][1]);
}