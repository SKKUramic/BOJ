// 2864 5와 6의 차이
// https://www.acmicpc.net/problem/2864
#include <stdio.h>
#include <string.h>

int main(){
	int five1 = 0, five2 = 0, six1 = 0, six2 = 0, idx;
	char num1[10], num2[10];
	scanf("%s %s", num1, num2);
	idx = 0;
	while (idx < strlen(num1)){
		if ((num1[idx] - '0') % 10 == 5 || (num1[idx] - '0') % 10 == 6){
			five1 = (five1 * 10) + 5;
			six1 = (six1 * 10) + 6;
		}
		else {
			five1 = (five1 * 10) + (num1[idx] - '0') % 10;
			six1 = (six1 * 10) + (num1[idx] - '0') % 10;	
		}
		idx++;
	}
	idx = 0;
	while (idx < strlen(num1)){
		if ((num2[idx] - '0') % 10 == 5 || (num2[idx] - '0') % 10 == 6){
			five2 = (five2 * 10) + 5;
			six2 = (six2 * 10) + 6;
		}
		else {
			five2 = (five2 * 10) + (num2[idx] - '0') % 10;
			six2 = (six2 * 10) + (num2[idx] - '0') % 10;	
		}
		idx++;
	}
	printf("%d %d", five1 + five2, six1 + six2);
}