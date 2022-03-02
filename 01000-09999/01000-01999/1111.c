// 1111 IQ Test
// https://www.acmicpc.net/problem/1111
#include <stdio.h>

// 이 문제는 a와 b의 조합이 하나가 아니어도 다음 수가 한 개로 특정되면 된다.
// x1 = arr[0], x2 = arr[1], x3 = arr[2]
// a * x1 + b = x2
// a * x2 + b = x3
// a = (x3 - x2) / (x2 - x1), b = x2 - a * x1

int main(){
	int N, a, b;
	int arr[51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	if (N == 1){
		printf("A"); // 다음 수를 향한 규칙 자체가 없음
		return 0;
	}
	else if (N == 2){
		if (arr[0] == arr[1]){ // 어차피 같은 수가 반복되므로 제외
			printf("%d", arr[0]);
			return 0;
		}
		else {
			printf("A"); // 두 수만으로는 규칙을 특정할 수 없음
			return 0;
		}
	}
	else {
		if (arr[0] == arr[1]){
			if (arr[1] == arr[2]){ // 3개의 원소를 본 결과 계속 연속된 수일 때
				a = 1; b = 0;
			}
			else { // 규칙이 깨짐
				printf("B");
				return 0;
			}
		}
		else {
			if (((arr[2] - arr[1]) / (arr[1] - arr[0])) * (arr[1] - arr[0]) != (arr[2] - arr[1])){ // a의 값이 정수가 아닐 때
				printf("B"); 
				return 0;
			}
			else {
				a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
				b = arr[1] -  a * arr[0];
			}
		}
		for (int i = 3; i < N; i++){
			if (arr[i] != a * arr[i - 1] + b){ // 0, 1, 2번째 원소의 규칙이 이후의 원소에 적용되지 않을 때
				printf("B");
				return 0;
			}
		}
		printf("%d", a * arr[N - 1] + b); // 규칙이 성립함
	}
}