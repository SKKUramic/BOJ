// 4342 유클리드 게임
// https://www.acmicpc.net/problem/4342
#include <stdio.h>

int win;

void Euclidean(long long a, long long b, int winner){ // winner턴에서의 상태
	if (a % b != 0){
		if (a / b >= 2){ // 상대에게 이지선다를 줄 수 있으므로 반드시 승리함
			win = winner;
			return;
		}
		else { // 다음 턴으로 넘길 수밖에 없을 때
			Euclidean(b, a - b, 3 - winner);
			return;
		}
	}
	else { // 'winner'턴의 사람이 지금 0으로 만들어버릴 수 있을 때
		win = winner;
		return;
	}
}

int main(){
	long long A, B;
	char answer;
	scanf("%lld %lld", &A, &B);
	while (A != 0 || B != 0){
		win = 0;
		if (A < B){
			Euclidean(B, A, 1);
		}
		else {
			Euclidean(A, B, 1);
		}
		answer = 'A' + (win - 1);
		printf("%c wins\n", answer);
		scanf("%lld %lld", &A, &B);
	}
}