// 17269 이름궁합 테스트
#include <stdio.h>
#include <string.h>

int alphabet_value(char c){
	if (c == 'C' || c == 'G' || c == 'I' || c == 'J' || c == 'L' || c == 'O' || c == 'S' || c == 'U' || c == 'V' || c == 'W' || c == 'Z'){
		return 1;
	}
	else if (c == 'B' || c == 'D' || c == 'N' || c == 'P' || c == 'Q' || c == 'R' || c == 'T' || c == 'X' || c == 'Y'){
		return 2;
	}
	else if (c == 'A' || c == 'F' || c == 'H' || c == 'K' || c == 'M'){
		return 3;
	}
	else if (c == 'E'){
		return 4;
	}
	else {
		return 0;
	}
}

int main(){
	char name1[101], name2[101];
	int chemi[201];
	int len1, len2, len, count = 0;
	scanf("%d %d", &len1, &len2);
	len = len1 > len2 ? len1 : len2;
	scanf("%s %s", name1, name2);
	for (int i = 0; i < len; i++){
		if (i < len1){
			chemi[count++] = alphabet_value(name1[i]);
		}
		if (i < len2){
			chemi[count++] = alphabet_value(name2[i]);
		}
	}
	while (count != 2){
		for (int i = 0; i < count - 1; i++){
			//printf("%d ", chemi[i]);
			chemi[i] = (chemi[i] + chemi[i + 1]) % 10;
		}
		//printf("\n");
		count--;
	}
	if (chemi[0] == 0){
		printf("%d%%", chemi[1]);
	}
	else {
		printf("%d%d%%", chemi[0], chemi[1]);
	}
	
}