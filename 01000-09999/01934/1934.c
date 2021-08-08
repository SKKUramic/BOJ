// 1934 최소공배수
#include <stdio.h>

int Euclidean(int a, int b){
	return a % b ? Euclidean(b, a % b) : b;
}

int main(){
	int test, a, b, gcd;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d", &a, &b);
		if (a > b){
			gcd = Euclidean(a, b);
		}
		else {
			gcd = Euclidean(b, a);
		}
		printf("%d\n", a * b / gcd);
	}
}