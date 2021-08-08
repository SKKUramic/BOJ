// 8958 OX퀴즈
#include <stdio.h>
#include <string.h>

int main(/*int argc, char* argv[]*/) {
	char OX[80];
	int num, len, adv = 0, score = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%s", OX);
		len = strlen(OX);
		for (int j = 0; j < len; j++){
			if (OX[j] == 'O'){
				adv++;
				score += adv;
			}
			else if (OX[j] == 'X'){
				adv = 0;
			}
			OX[j] = '\0';
		}
		printf("%d\n", score);
		score = 0;
		adv = 0;
	}
}