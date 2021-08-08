//1212 8진수 2진수
#include <stdio.h>
#include <string.h>

int main(){
	char eight[333335];
	char two[1000008];
	int len;
	int flags = 0;
	scanf("%s", eight);
	len = strlen(eight);
	if (eight[0] == '0' && eight[1] == '\0'){
		printf("%c", eight[0]);
		return 0;
	}
	for (int i = 0; i < len; i++){
		two[3 * i] = ((eight[i] - '0') / 4) % 2 + '0';
		two[3 * i + 1] = ((eight[i] - '0') / 2) % 2 + '0';
		two[3 * i + 2] = (eight[i] - '0') % 2 + '0';
	}
	for (int j = 0; j < 3 * len; j++){
		if (flags == 0 && two[j] == '1'){
			flags = 1;
		}
		if (flags == 1){
			printf("%c", two[j]);	
		}
	}
	return 0;
}