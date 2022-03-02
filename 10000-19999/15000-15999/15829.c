// 15829 Hashing
#include <stdio.h>
//#include <string.h>

const int r = 31;
const int M = 1234567891;
char number[50];

int main(){
	long long int sum = 0, temp;
	int len;
	scanf("%d", &len);
	scanf("%s", number);
	for (int i = 0; i < len; i++){
		temp = number[i] - 'a' + 1;
		for (int k = 0; k < i; k++){
			temp *= r;
			temp %= M;
		}
		//printf("%lld\n", temp);
		sum += temp;
		sum %= M;
	}
	printf("%lld", sum);
}