// 14211 슬라임 합치기
// https://www.acmicpc.net/problem/14241
// 작은 것끼리 합쳐 나가는 것이 최댓값
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long v[1000];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N, num, score = 0;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> v[i];
	}
	sort(v, v + N, greater<>());
	while (N > 1){
		score += v[N - 1] * v[N - 2];
		v[N - 2] = v[N - 1] + v[N - 2];
		N--;
	}
	cout << score;
}