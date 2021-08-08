#include <stdio.h>
#include <string.h>

int main(){
	int len, count = 0;
	// char Croatia[8][3] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	char word[103];
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		if (word[i] == 'c'){
			if (word[i + 1] == '=' || word[i + 1] == '-'){
				i += 1;
			}
		}
		else if (word[i] == 'd'){
			if (word[i + 1] == '-'){
				i += 1;
			}
			else if (word[i + 1] == 'z' && word[i + 2] == '='){
				i += 2;
			}
		}
		else if (word[i] == 'l' && word[i + 1] == 'j'){
			i += 1;
		}
		else if (word[i] == 'n' && word[i + 1] == 'j'){
			i += 1;
		}
		else if (word[i] == 's' && word[i + 1] == '='){
			i += 1;
		}
		else if (word[i] == 'z' && word[i + 1] == '='){
			i += 1;
		}
		count++;
	}
	printf("%d", count);
}