// 12728 n제곱 계산
// https://www.acmicpc.net/problem/12728
#include <iostream>
using namespace std;

long long answer_matrix[2][2] = {{1, 0}, {0, 1}}; // 단위행렬
long long matrix[2][2] = {{6, -4}, {1, 0}}; // 행렬
long long temp_matrix[2][2] = {{0, 0}, {0, 0}}; // 임시로 답을 계산하는 행렬

long long matrix_exponentiatiion(long long N){
	answer_matrix[0][0] = 1; answer_matrix[0][1] = 0; answer_matrix[1][0] = 0; answer_matrix[1][1] = 1;
	matrix[0][0] = 6; matrix[0][1] = -4; matrix[1][0] = 1; matrix[1][1] = 0;
	while (N > 0){
		temp_matrix[0][0] = 0; temp_matrix[0][1] = 0; temp_matrix[1][0] = 0; temp_matrix[1][1] = 0;
		if (N % 2 == 1){
			for (int a = 0; a < 2; a++){
				for (int b = 0; b < 2; b++){
					for (int c = 0; c < 2; c++){
						temp_matrix[a][b] += answer_matrix[a][c] * matrix[c][b];
						temp_matrix[a][b] %= 1000000; 
					}
				}
			}
			for (int a = 0; a < 2; a++){
				for (int b = 0; b < 2; b++){
					answer_matrix[a][b] = temp_matrix[a][b];
				}
			}
		}
		temp_matrix[0][0] = 0; temp_matrix[0][1] = 0; temp_matrix[1][0] = 0; temp_matrix[1][1] = 0;
		for (int a = 0; a < 2; a++){
			for (int b = 0; b < 2; b++){
				for (int c = 0; c < 2; c++){
					temp_matrix[a][b] += matrix[a][c] * matrix[c][b];
					temp_matrix[a][b] %= 1000000; 
				}
			}
		}
		for (int a = 0; a < 2; a++){
			for (int b = 0; b < 2; b++){
				matrix[a][b] = temp_matrix[a][b];
			}
		}
		N /= 2;
	}
	return (answer_matrix[1][0] * 28 + answer_matrix[1][1] * 6) - 1;
}

int main(){
	long long N, answer;
	int TC;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++){
		scanf("%lld", &N);
		answer = matrix_exponentiatiion(N - 1);
		answer %= 1000;
		if (answer < 0){answer += 1000;} // 왜 음수가 나오는지는 잘 모르겠음
		if (answer >= 100){
			printf("Case #%d: %lld\n", t, answer);
		}
		else if (answer >= 10){
			printf("Case #%d: 0%lld\n", t, answer);
		}
		else {
			printf("Case #%d: 00%lld\n", t, answer);
		}
	}
}

/*
a = 3 + sqrt(5), b = 3 - sqrt(5)라고 가정하자.
a + b = 6, ab = 4이므로
a와 b는 x^2- 6x + 4 = 0의 두 해이다
따라서 x^(n + 2) - 6x^(n + 1) + 4x^n = 0의 해도 a와 b이다.
즉, 이하의 식이 성립한다

a^(n + 2) - 6a^(n + 1) + 4a^n = 0
b^(n + 2) - 6b^(n + 1) + 4b^n = 0

두 식을 적절히 합성하면 이하의 방정식이 성립한다
a^(n + 2) + b^(n + 2) = 6(a^(n + 1) + b^(n + 1)) - 4(a^n + b^n)

이때, a^n + b^n = Pn이라고 가정하자. 이때 Pn이 항상 정수인지 확인하도록 한다.
1. 기저 사례
P1 = 6, P2 = 28, P3 = 144이며, 항상 정수이다.

2. P(n - 1)과 Pn이 정수일 때, P(n+1)도 정수인가(n >= 3)
위에서 구한 방정식을 변환하면 P(n + 2) = 6 * P(n + 1) - 4 * Pn이며, 이는 n이 n - 1으로 바뀌어도 성립한다.
정수 간의 덧셈, 곱셈, 뺄셈의 답은 항상 정수이므로 P(n + 1)도 항상 정수이다.

이제 Pn으로 답을 구하는 방법을 알아보자.
0 < b < 1이므로 항상 0 < b^n < 1을 만족한다.
answer < a^n < answer + 1이므로 a^n + b^n = answer + 1이다. 따라서 Pn - 1 = answer이다.
*/