// 18222 투에-모스 문자열
#include <stdio.h>

int main(){
	long long k;
	int one = 0;
	scanf("%lld", &k);
	k--;
	while (k > 0){
		if (k % 2 == 1){one++;}
		k /= 2;
	}
	if (one % 2 == 1){printf("1");}
	else {printf("0");}
}