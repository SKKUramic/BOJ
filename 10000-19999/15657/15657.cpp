// 15657 N과 M(8)
// https://www.acmicpc.net/problem/15657
// nΠm 구현 문제
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int save[10];
bool visited[10];

void nHm(int idx){
	if (idx == M){
		for (int i = 1; i < M; i++){ // 검증(가지치기 하기 싫음ㅎ)
			if (save[i - 1] > save[i]){
				return;
			}
		}
		for (int i = 0; i < M; i++){
			cout << save[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++){
		save[idx] = arr[i];
		nHm(idx + 1);
	}
}

int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	nHm(0);
}