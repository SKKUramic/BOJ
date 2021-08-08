// 15663 N과 M(9)
// https://www.acmicpc.net/problem/15663
// nPm 구현 문제이긴 한데, 같은 경우는 제외함
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int N, M;
int arr[10];
int save[10];
bool visited[10];
set<string> inside; // 중복이 있으면 제거함, 즉 중복을 넣어도 크기가 바뀌지 않음

void nPm(int n, int idx){
	if (idx == M){
		int size_before;
		string s = "";
		for (int i = 0; i < M; i++){
			s = s + to_string(save[i]);
		}
		size_before = inside.size();
		inside.insert(s);
		if (size_before == inside.size()){return;}
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