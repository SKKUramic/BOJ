// 2568 전깃줄 - 2
// https://www.acmicpc.net/problem/2568
// LIS를 구한 후, 길이가 그게 더 길면 그걸 제외한 것들을 출력
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

bool flag;
pii arr[500001], LIS[500001], NOPE[500001], answer[500001];
int IDX[500001] = {0, };

int proper_idx(int left, int right, int input){
	int middle;
	while (left < right){
		middle = (left + right) / 2;
		if (LIS[middle].second >= input){right = middle;}
		else {left = middle + 1;}
	}
	return left;
}

int main(){
	int N, len = 1, idx, ans_len, NOPE_idx = 0;
	pii p;
	scanf("%d", &N);
	LIS[0] = {0, -1111111111};
	for (int i = 0; i < N; i++){
		scanf("%d %d", &p.first, &p.second);
		arr[i] = p;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++){
		if (LIS[len - 1].second < arr[i].second){
			IDX[i] = len;
			LIS[len++] = arr[i];
		}
		else{
			idx = proper_idx(0, len, arr[i].second);
			IDX[i] = idx;
			LIS[idx] = arr[i];
		}
	}
	ans_len = len - 1;
	idx = N - 1;
	while (ans_len > 0){
		flag = true;
		if (IDX[idx] == ans_len){
			answer[ans_len--] = arr[idx];
			flag = false;
		}
		if (flag == true) {
			NOPE[NOPE_idx++] = arr[idx];
		}
		idx--;
	}
	while (idx >= 0){
		NOPE[NOPE_idx++] = arr[idx];
		idx--;
	}
	printf("%d\n", NOPE_idx);
	for (int i = NOPE_idx - 1; i >= 0; i--){ 
		printf("%d\n", NOPE[i].first);
	}
}