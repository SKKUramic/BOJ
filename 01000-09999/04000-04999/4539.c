// 4539 반올림
// https://www.acmicpc.net/problem/4539
#include <stdio.h>

long long upup(long long X){
	long long ten = 10;
	while (X > ten){
		if ((X % ten) / (ten / 10) >= 5){
			X = (X - X % ten) + ten;
		}
		else {
			X -= (X % ten);
		}
		ten *= 10;
	}
	return X;
}

int main(){
	int N;
	long long X;
	scanf("%d", &N);
	while (N-- > 0){
		scanf("%lld", &X);
		printf("%lld\n", upup(X));
	}
}