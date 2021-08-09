// 9661 돌 게임 7
// https://www.acmicpc.net/problem/9661
#include <stdio.h>

int main(){
	int arr[5] = {1, 0, 1, 0, 0}; // 1일 때 CY 승리, 0일 때 SK 승리
	// 기저 사례: arr[1]: SK, arr[2]: CY, arr[3]: SK, arr[4]: SK
	// arr[N]: arr[N - 4^0], arr[N - 4^1], ... , arr[N - 4^k]가 모두 같으면 반대 사람이, 다르면 SK가 승리한다. (단, k는 N > 4^k을 만족하는 0 이상의 정수)
	long long N; // arr[N % 5]가 승리하는 사람이다. 이게 뭐지???
	scanf("%lld", &N);
	if (arr[N % 5] == 0){printf("SK");}
	else if (arr[N % 5] == 1){printf("CY");}
}