// 1664 소수의 연속합
// https://www.acmicpc.net/problem/1644
#include <iostream>
#include <time.h>
using namespace std;

int prime[4000000];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flags;
	int N, prime_count = 1, start, end, sum, answer = 0;
	cin >> N;
	clock_t t_start = clock();
	if (N == 1){cout << 0; return 0;}
	else if (N == 2) {cout << 1; return 0;}
	prime[0] = 2;
	for (int i = 3; i <= N; i += 2){
		flags = true;
		for (int j = 0; prime[j] * prime[j] <= i; j++){
			if (i % prime[j] == 0){
				flags = false;
				break;
			}
		}
		if (flags){
			prime[prime_count++] = i;
		}
	}
	start = 0; end = 0; sum = prime[0];
	while (start <= end && end < prime_count){
		if (sum < N){
			sum += prime[++end];
		}
		else if (sum == N){
			answer++;
			sum += prime[++end];
		}
		else {
			sum -= prime[start++];
		}
	}
	cout << answer;
	clock_t t_end = clock();
	//cout << (double)(t_end - t_start) / CLOCKS_PER_SEC;
}