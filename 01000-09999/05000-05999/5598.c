// 5598 카이사르 암호
#include <stdio.h>

int main(){
	char caesar[1001];
	scanf("%s", caesar);
	for (int i = 0; caesar[i] != '\0'; i++){
		caesar[i] -= 3;
		if (caesar[i] < 'A'){
			caesar[i] += ('Z' - 'A' + 1);
		}
		printf("%c", caesar[i]);
	}
}