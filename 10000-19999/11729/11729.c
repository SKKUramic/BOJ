// 11729 하노이 탑 이동 순서
#include <stdio.h>

int move[1200000][2]= {0, };

void hanoi(int shell, int start, int through, int end){
	if (shell == 1){printf("%d %d\n", start, end);}
	else {
		hanoi(shell - 1, start, end, through);
		printf("%d %d\n", start, end);
		hanoi(shell - 1, through, start, end);
	}
	return;
}

int main(){
	int K, count = 1;
	scanf("%d", &K);
	for (int i = 0; i < K; i++){
		count *= 2;
	}
	count--;
	printf("%d\n", count);
	hanoi(K, 1, 2, 3);
}