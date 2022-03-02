// 10819 차이를 최대로 
// https://www.acmicpc.net/problem/10819
// 15654 N과 M(5) 문제 풀이에서 가져왔습니다
#include <iostream>
#include <cstdlib>
using namespace std;

int N, M, max_sum = -1;
int arr[10];
int save[10];
bool visited[10];

void nPm(int n, int idx){
	int sum = 0;
	if (idx == M){
		for (int i = 0; i < N - 1; i++){
			sum += abs(save[i] - save[i + 1]);
		}
		if (max_sum < sum) {max_sum = sum;}
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
		cin >> arr[i];
	}
	nPm(N, 0);
	cout << max_sum;
}