// 4690 완전 세제곱
// https://www.acmicpc.net/problem/4690
#include <stdio.h>

typedef long long ll;

int main(){
	for (ll a = 2; a <= 100; a++){
		for (ll b = 2; b <= a; b++){
			for (ll c = b; c <= a; c++){
				for (ll d = c; d <= a; d++){
					if (a * a * a == b * b * b + c * c * c + d * d * d){
						printf("Cube = %lld, Triple = (%lld,%lld,%lld)\n", a, b, c, d);
					}
				}
			}
		}
	}
}