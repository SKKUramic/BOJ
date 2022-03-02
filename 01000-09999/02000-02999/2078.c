// 2078 무한이진트리
// https://www.acmicpc.net/problem/2078
#include <stdio.h>

int main(){
	long long A, B, Lcount = 0, Rcount = 0;
	scanf("%lld %lld", &A, &B);
	while (A != 1 || B != 1){
		if (A > B){
			if (B == 1){
				Lcount += (A - 1);
				A = 1;
			}
			else {
				Lcount += (A / B);
				A -= (A / B) * B;
			}
		}
		else {
			if (A == 1){
				Rcount += (B - 1);
				B = 1;
			}
			else {
				Rcount += (B / A);
				B -= (B / A) * A;
			}
		}
	}
	printf("%lld %lld", Lcount, Rcount);
}