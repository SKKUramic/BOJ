// 1441 나누어 질까
// https://www.acmicpc.net/problem/1441
#include <stdio.h>

long long Lanswer = 0, Ranswer = 0, L, R;
long long arr[21];
int N;

long long Euclidean(long long a, long long b){
	return a % b ? Euclidean(b, a % b) : b;
}

void Lcoprime(int idx, long long num, int count){
	if (num > L){return;}
	if (idx == N - 1 && num != 1LL){
		if (count % 2 == 1){Lanswer += L / num;}
		else {Lanswer -= L / num;}
		return;
	}
	Lcoprime(idx + 1, (num * arr[idx + 1]) / Euclidean(num, arr[idx + 1]), count + 1);
	Lcoprime(idx + 1, num, count);
	return;
}

void Rcoprime(int idx, long long num, int count){
	if (num > R){return;}
	if (idx == N - 1 && num != 1LL){
		if (count % 2 == 1){Ranswer += R / num;}
		else {Ranswer -= R / num;}
		return;
	}
	Rcoprime(idx + 1, (num * arr[idx + 1]) / Euclidean(num, arr[idx + 1]), count + 1);
	Rcoprime(idx + 1, num, count);
	return;
}

int main(){
	scanf("%d %lld %lld", &N, &L, &R); L--;
	for (int i = 0; i < N; i++){
		scanf("%lld", &arr[i]);
		if (arr[i] == 1LL){ // 모든 자연수는 1로 나누어 떨어진다
			printf("%lld", R - L);
			return 0;
		}
	}
	for (int i = 0; i < N; i++){
		Lcoprime(i, arr[i], 1);
		Rcoprime(i, arr[i], 1);
	}
	printf("%lld", Ranswer - Lanswer);
}