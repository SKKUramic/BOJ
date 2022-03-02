// 2153 소수 단어
// https://www.acmicpc.net/problem/2153
#include <stdio.h>
#include <string.h>

int main(){
	int len, sum = 0;
	char word[22];
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		if (word[i] >= 'a' && word[i] <= 'z'){
			sum += (word[i] - 'a' + 1);
		}
		else {
			sum += (word[i] - 'A' + 27);
		}
		
	}
	if (sum == 0){
		printf("It is not a prime word.");
		return 0;
	}
	for (int i = 2; i * i <= sum; i++){
		if (sum % i == 0){
			printf("It is not a prime word.");
			return 0;
		}
	}
	printf("It is a prime word.");
	return 0;
}