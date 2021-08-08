// 2805 나무 자르기
#include <bits/stdc++.h>
using namespace std;

long long tree[1000001];

int main(){
	long long N, M;
	cin >> N >> M;
	long long max = 0;
	long long answer = 0;
	for (long long i = 0; i < N; i++){
		cin >> tree[i];
		if (max < tree[i]){
			max = tree[i];
		}
	}
	long long left = 0;
	long long right = max;
	while (left <= right){
		long long middle = (left + right) / 2;
		long long total = 0;
		for (long long k = 0; k < N; k++){
			if (middle < tree[k]){
				total += tree[k] - middle;
			}
		}
		if (total >= M){
			if (answer <= middle){
				answer = middle;
			}
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	cout << answer << endl;
	return 0;
}