// 1003 피보나치 함수
#include <stdio.h>

int zero[50] = {0, };
int one[50] = {0, };

int count_zero(int x){
	if (x <= 1 || zero[x] != 0){
		return zero[x];
	}
	zero[x] = count_zero(x - 1) + count_zero(x - 2);
	return zero[x];
}

int count_one(int x){
	if (x <= 1 || one[x] != 0){
		return one[x];
	}
	one[x] = count_one(x - 1) + count_one(x - 2);
	return one[x];
}

int main(){
	int test, temp;
	zero[0] = 1;
	one[1] = 1;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d", &temp);
		printf("%d %d\n", count_zero(temp), count_one(temp));
	}
}