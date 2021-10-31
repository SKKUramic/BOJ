// 9359 서로소
// https://www.acmicpc.net/problem/9359
#include <stdio.h>

long long A, B, N, temp;
long long Aans, Bans, arr[11];
int Idx;

void coprime(int idx, long long num, int count){
	if (num > B){return;} // 너무 큰데요
	if (idx == Idx - 1){
		if (count % 2 == 1){
			if (A >= num){Aans += A / num;}
			Bans += B / num;
		}
		else {
			if (A >= num){Aans -= A / num;}
			Bans -= B / num;
		}
		return;
	}
	coprime(idx + 1, num * arr[idx + 1], count + 1);
	coprime(idx + 1, num, count);
	return;
}

int main(){
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++){
		Aans = 0; Bans = 0;
		scanf("%lld %lld %lld", &A, &B, &N);
		temp = N; Idx = 0; A--;
		for (long long i = 2; i * i <= N; i++){
			if (temp % i == 0){
				arr[Idx++] = i;
				while (temp % i == 0){temp /= i;}
			}
			if (temp == 1LL){break;}
		}
		if (temp != 1LL){arr[Idx++] = temp;}
		for (int i = 0; i < Idx; i++){
			coprime(i, arr[i], 1);
		}
		printf("Case #%d: %lld\n", tc, (B - A) - (Bans - Aans));
	}
	
}