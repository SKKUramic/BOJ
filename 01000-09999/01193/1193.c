// 1193 분수찾기
#include <stdio.h>

int main(){
	int N, k = 1, max;
	int parent, child;
	scanf("%d", &N);
	while(k*(k+1)/2 < N){
		k++;
	}
	max = k * (k + 1) / 2;
	//k++;
	parent = (k % 2 == 0) ? 1 : k;
	child = (k % 2 == 0) ? k : 1;
	while (max != N){
		if (k % 2 == 0){
			child--;
			parent++;
		}
		else {
			parent--;
			child++;
		}
		max--;
	}
	printf("%d/%d", child, parent);
}