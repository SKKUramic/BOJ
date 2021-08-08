// 11279 최대 힙
#include <stdio.h>

int tree[100001] = {0, };
int SIZE = 0;

void print_maxheap(){ // 디버그용
	printf("\nprintng maxheap...\n");
	int idx = 1;
	while (idx <= 15){
		for (int i = idx; i < 2 * idx; i++){
			printf("%d ", tree[i]);
		}
		printf("\n");
		idx *= 2;
	}
	printf("SIZE: %d\n", SIZE);
	printf("printng maxheap ends\n");
	return;
}

void maxheap(int a){
	int idx, temp, child;
	if (a == 0){ // 원소를 뽑을 때
		if (SIZE == 0){ // 힙이 비어있을 때
			printf("0\n");
			return;
		}
		else { // 힙이 비어있지 않을 때
			printf("%d\n", tree[1]); // 가장 큰 값을 출력
			tree[1] = tree[SIZE];
			tree[SIZE--] = 0;
			idx = 1;
			while (1){
				child = 2 * idx;
				if (child + 1 <= SIZE && tree[child] < tree[child + 1]){
					child++;
				}
				if (child > SIZE || tree[child] < tree[idx]){
					break;
				}
				temp = tree[idx];
				tree[idx] = tree[child];
				tree[child] = temp;
				idx = child;
			}
			return;
		}
	}
	
	else { // 힙에 a라는 값을 넣으려고 할 때
		SIZE++;
		idx = SIZE;
		tree[idx] = a; // 일단 넣고 본다
		while (idx != 1){ // idx = 2까지 검사함
			if (tree[idx] > tree[idx / 2]){ // 부모보다 내가 더 클 때
				temp = tree[idx];
				tree[idx] = tree[idx / 2];
				tree[idx / 2] = temp;
				idx /= 2; // 부모와 나의 값을 서로 바꾼 후, 부모의 주소로 올라감
			}
			else {
				break; // 여기가 끝이므로 종료
			}
		}
		return;
	}
	return;
}

int main(){
	int N, number;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &number);
		maxheap(number);
	}
}