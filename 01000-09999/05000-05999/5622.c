// 5622 다이얼
#include <stdio.h>
#include <string.h>

int main(){
	char word[20];
	int len, count = 0;
	scanf("%s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++){
		if (word[i] < 68){
			count += 3;
		}
		else if (word[i] < 71){
			count += 4;
		}
		else if (word[i] < 74){
			count += 5;
		}
		else if (word[i] < 77){
			count += 6;
		}
		else if (word[i] < 80){
			count += 7;
		}
		else if (word[i] < 84){
			count += 8;
		}
		else if (word[i] < 87){
			count += 9;
		}
		else {
			count += 10;
		}
	}
	printf("%d", count);
}