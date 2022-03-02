// 2042 구간 합 구하기
// https://www.acmicpc.net/problem/2042
// 세그먼트 트리를 배우기 좋은 문제, https://mapocodingpark.blogspot.com/2020/02/BOJ-2042.html 마포 코딩박님의 코드를 보며 배우고 풀었습니다.
#include <iostream>
#define MAX 1048576
using namespace std;

int N, M, K;
int update_or_sum;
long long data, Lnum, Rnum;
long long tree[2097152]; // MAX의 두 배

void update(long long idx, long long num){
	tree[idx] = num;
	while (idx > 1){
		idx /= 2;
		tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	}
	return;
}

long long find_sum(int node, long long int left, long long int right){
	if (left > Rnum || right < Lnum){return 0;} // 범위를 벗어났을 경우
	if (node >= MAX){return tree[node];}
	if (Lnum <= left && right <= Rnum){return tree[node];}
	int middle = (left + right) / 2;
	return find_sum(2 * node, left, middle) + find_sum(2 * node + 1, middle + 1, right);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (long long int i = 0; i < N; i++){
		cin >> data;
		update(MAX + i, data);
	}
	for (int i = 0; i < M + K; i++){
		cin >> update_or_sum >> Lnum >> Rnum;
		if (update_or_sum == 1){ // updating number
			update(MAX + Lnum - 1, Rnum);
		}
		else if (update_or_sum == 2){ // find sum
			cout << find_sum(1, 1, MAX) << '\n';
		}
	}
}