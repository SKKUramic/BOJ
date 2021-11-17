// 11003 최솟값 찾기
// https://www.acmicpc.net/problem/11003
// https://jaimemin.tistory.com/746(꾸준함님의 블로그)에서 배웠습니다
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int arr[5000001];
deque<pair<int, int>> dq; // 값, index

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	for (int n = 0; n < N; n++){
		cin >> arr[n];
	}
	for (int n = 0; n < N; n++){
		if (!dq.empty() && dq.front().second <= n - L){ // dq 맨 앞의 원소(최솟값)가 더이상 범위에 안 들어가면
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().first > arr[n]){ // dq 안에서 최솟값이 아닌 원소는 필요가 없다
			dq.pop_back();
		}
		dq.push_back({arr[n], n});
		cout << dq.front().first << ' '; // 현재 최솟값 출력
	}
}