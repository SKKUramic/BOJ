// 4999 아!
// https://www.acmicpc.net/problem/4999
// 이게 브론즈 2?
#include <stdio.h>
#include <string.h>

int main(){
	char AH_me[1001];
	char AH_doctor[1001];
	scanf("%s", AH_me);
	scanf("%s", AH_doctor);
	if (strlen(AH_me) < strlen(AH_doctor)){
		printf("no");
	}
	else {
		printf("go");
	}
}