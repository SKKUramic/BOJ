// 10757 큰 수 A+B
#include <stdio.h>
#include <string.h>

int main(){
	char num1[10002] = {0, }, num2[10002] = {0, }, answer[10003] = {0, };
	int len1, len2, len, carry = 0;
	scanf("%s %s", num1, num2);
	len1 = strlen(num1);
	len2 = strlen(num2);
	len = len1 > len2 ? len1 : len2;
	// printf("%d\n", len);
	for (int i = 0; i <= len; i++){
		answer[i] = num1[len1 - i - 1] - '0' + num2[len2 - i - 1] - '0' + carry;
		// printf("ㅎㅎ%d\n", answer[i]);
		while (answer[i] < '0'){answer[i] += '0';}
		// printf("ㅎㅎ%d\n", answer[i]);
		if (answer[i] > '9'){
			answer[i] -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		// printf("ㅎㅎ%c\n", answer[i]);
	}
	len = strlen(answer);
	if (answer[len - 1] != '0'){
		printf("%c", answer[len - 1]);
	}
	for(int i = len - 2; i >= 0; i--){
		printf("%c", answer[i]);
	}
}