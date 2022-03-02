// 2942 퍼거슨과 사과
// https://www.acmicpc.net/problem/2942
#include <stdio.h>

int gcd(int a, int b){
	return a % b ? gcd(b, a % b) : b;
}

int main(){
	int red, green, GCD;
	scanf("%d %d", &red, &green);
	GCD = gcd(red, green);
	for (int i = 1; i * i <= GCD; i++){
		if (GCD % i == 0){
			printf("%d %d %d\n", i, red / i, green / i);
			if (i * i != GCD){
				printf("%d %d %d\n", GCD / i, red / (GCD / i), green / (GCD / i));
			}
		}
	}
}