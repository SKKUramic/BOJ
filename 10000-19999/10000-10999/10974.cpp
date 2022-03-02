// 10974 모든 순열
// https://www.acmicpc.net/problem/10974
// 15654 N과 M(5) 문제 풀이에서 가져왔습니다
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int save[10];
bool visited[10];

void nPm(int n, int idx){
	if (idx == M){
		for (int i = 0; i < M; i++){
			cout << save[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++){
		if (visited[i] == false){
			save[idx] = arr[i];
			visited[i] = true;
			nPm(n, idx + 1);
			visited[i] = false;
		}
	}
}

int main(){
	cin >> N;
	M = N;
	for (int i = 0; i < N; i++){
		arr[i] = i + 1;
	}
	nPm(N, 0);
}