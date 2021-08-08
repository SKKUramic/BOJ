// 2357 최솟값과 최댓값
// https://www.acmicpc.net/problem/2357
#include <iostream>
#define MAX 131072
#define MAX_INT 2147483647
using namespace std;

int N, M, NUM, LEFT, RIGHT;
int min_heap[262144];
int max_heap[262144];

void update(int idx, int num){
	min_heap[idx] = num;
	max_heap[idx] = num;
	while (idx > 1){
		idx /= 2;
		min_heap[idx] = min_heap[2 * idx] < min_heap[2 * idx + 1] ? min_heap[2 * idx] : min_heap[2 * idx + 1];
		max_heap[idx] = max_heap[2 * idx] > max_heap[2 * idx + 1] ? max_heap[2 * idx] : max_heap[2 * idx + 1];
	}
	return;
}

int find_min(int node, int left, int right){
	if (right < LEFT || RIGHT < left){return MAX_INT;}
	if (node >= MAX){return min_heap[node];}
	if (LEFT <= left && right <= RIGHT){return min_heap[node];}
	int middle = (left + right) / 2;
	int left_min, right_min;
	left_min = find_min(node * 2, left, middle);
	right_min = find_min(node * 2 + 1, middle + 1, right);
	return left_min < right_min ? left_min : right_min;
}

int find_max(int node, int left, int right){
	if (right < LEFT || RIGHT < left){return -1;}
	if (node >= MAX){return max_heap[node];}
	if (LEFT <= left && right <= RIGHT){return max_heap[node];}
	int middle = (left + right) / 2;
	int left_max, right_max;
	left_max = find_max(node * 2, left, middle);
	right_max = find_max(node * 2 + 1, middle + 1, right);
	return left_max > right_max ? left_max : right_max;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 2 * MAX; i++){
		min_heap[i] = MAX_INT;
		max_heap[i] = -1;
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> NUM;
		update(MAX + i, NUM);
	}
	for (int i = 0; i < M; i++){
		cin >> LEFT >> RIGHT;
		cout << find_min(1, 1, MAX) << ' ' << find_max(1, 1, MAX) << '\n';
	}
}