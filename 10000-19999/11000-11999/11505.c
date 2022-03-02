// 11505 구간 곱 구하기
// https://www.acmicpc.net/problem/11505
#include <stdio.h>
#define MAX 1048576

int N, M, K, upsum, Lnum, Rnum;
long long data, REMAINDER = 1000000007;
long long tree[2097152] = {0, };

void update(int idx, long long num){
	tree[idx] = num;
	while (idx > 1){
		idx /= 2;
		tree[idx] = ((tree[2 * idx] % REMAINDER) * (tree[2 * idx + 1] % REMAINDER)) % REMAINDER; // 나머지 연산 다 해줌
		if (tree[idx] < 0){tree[idx] = -tree[idx];} // 음수로 계산될 경우 양수로 바꿔줌
	}
	return;
}

long long find_multiple(int node, int left, int right){
	if (left > Rnum || right < Lnum){return 1;} // 범위를 벗어났을 경우
	if (node >= MAX){
		if (tree[node] == -1){return 1;} // 그럴 일은 없겠지만 만약 참조하면 안 되는 곳에 가버렸다면
		else {return tree[node];}
	}
	if (Lnum <= left && right <= Rnum){
		if (tree[node] == -1){return 1;} // 그럴 일은 없겠지만 만약 참조하면 안 되는 곳에 가버렸다면
		else {return tree[node];}
	}
	int middle = (left + right) / 2;
	return ((find_multiple(2 * node, left, middle) % REMAINDER) * (find_multiple(2 * node + 1, middle + 1, right) % REMAINDER)) % REMAINDER; // 나머지 연산 다 해줌
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i <= 2097151; i++){tree[i] = -1;} // 0도 들어갈 수 있어서 전부 다 -1로 초기화함, -1이랑 곱하면 부호는 바뀔지언정 절댓값은 안 바뀌므로
	for (int i = 0; i < N; i++){
		scanf("%lld", &data);
		update(MAX + i, data);
	}
	for (int i = 0; i < M + K; i++){
		scanf("%d %d %d", &upsum, &Lnum, &Rnum);
		if (upsum == 1){
			update(MAX + Lnum - 1, Rnum);
		}
		else if (upsum == 2){
			printf("%lld\n", find_multiple(1, 1, MAX));	
		}
	}
}