// 12849 본대 산책
// https://www.acmicpc.net/problem/12849
// 12850 본대 산책2와 풀이가 동일합니다, 애시당초 이게 Small이고 12850이 Large라고 보시면 됩니다.
#include <stdio.h>

long long REMAINDER = 1000000007;
long long arr[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 1, 0, 0},
	{0, 1, 1, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 1, 1, 1},
	{0, 0, 1, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 1, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};
long long answer[8][8]; // 단위 행렬

void Multi_matrix(long long A[][8], long long B[][8]){
	unsigned long long int temp[8][8] = {0, };
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			for (int k = 0; k < 8; k++){
				temp[i][j] += A[i][k] * B[k][j];
			}
			temp[i][j] %= REMAINDER;
		}
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			A[i][j] = temp[i][j];
		}
	}
	return;
}

int main(){
	long long D;
	scanf("%lld", &D);
	for (int i = 0; i < 8; i++){
		answer[i][i] = 1;
	}
	while (D > 0){
		if (D % 2 == 1){
			Multi_matrix(answer, arr);
		}
		Multi_matrix(arr, arr);
		D /= 2;
	}
	printf("%lld", answer[7][7]);
}