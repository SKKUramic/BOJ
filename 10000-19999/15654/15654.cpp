// 15654 N과 M(5)
// https://www.acmicpc.net/problem/15654
// nPm 구현 문제
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
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	nPm(N, 0);
}