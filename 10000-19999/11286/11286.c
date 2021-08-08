// 11286 절댓값 힙
// 11279 최대 힙의 변형판
#include <stdio.h>
#include <stdlib.h>

int tree[100001] = {0, };
int SIZE = 0;

void print_minheap(){ // 디버그용
	printf("\nprintng minheap...\n");
	int idx = 1;
	while (idx <= 15){
		for (int i = idx; i < 2 * idx; i++){
			printf("%d ", tree[i]);
		}
		printf("\n");
		idx *= 2;
	}
	printf("SIZE: %d\n", SIZE);
	printf("printng minheap ends\n");
	return;
}

void minheap(int a){
	int idx, temp, child;
	if (a == 0){ // 원소를 뽑을 때
		if (SIZE == 0){ // 힙이 비어있을 때
			printf("0\n");
			return;
		}
		else { // 힙이 비어있지 않을 때
			printf("%d\n", tree[1]); // 가장 절댓값이 작은 값을 출력
			tree[1] = tree[SIZE];
			tree[SIZE--] = 0;
			idx = 1;
			while (1){
				child = 2 * idx;
				if (child + 1 <= SIZE){
					if (abs(tree[child]) > abs(tree[child + 1])){ // 왼쪽 자식이 오른쪽 자식보다 절댓값이 클 때
						//printf("!\n");
						child++;
					}
					else if (abs(tree[child]) == abs(tree[child + 1]) && tree[child] > tree[child + 1]){ // 두 자식의 절댓값이 같으나 왼쪽 자식이 음수, 오른쪽 자식이 양수일 때
						//printf("?\n");
						child++;
					}
				}
				if (child > SIZE || abs(tree[child]) > abs(tree[idx])){
					break;
				}
				if (abs(tree[idx]) == abs(tree[child]) && tree[idx] < tree[child]){
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
			if (abs(tree[idx]) < abs(tree[idx / 2])){ // 부모보다 내 절댓값이 더 작을 때
				temp = tree[idx];
				tree[idx] = tree[idx / 2];
				tree[idx / 2] = temp;
				idx /= 2; // 부모와 나의 값을 서로 바꾼 후, 부모의 주소로 올라감
			}
			else if (abs(tree[idx]) == abs(tree[idx / 2]) && tree[idx] < tree[idx / 2]){ // 절댓값은 같으나 자식은 음수 부모는 양수일 때
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
		minheap(number);
		//print_minheap();
	}
}