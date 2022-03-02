// 5613 계산기 프로그램
// https://www.acmicpc.net/problem/5613
#include <stdio.h>

int main(){
	int answer, num;
	char c[3];
	scanf("%d", &answer);
	while (1){
		scanf("%s", c);
		if (c[0] == '='){break;}
		scanf("%d", &num);
		if (c[0] == '+'){answer += num;}
		else if (c[0] == '-'){answer -= num;}
		else if (c[0] == '*'){answer *= num;}
		else if (c[0] == '/'){answer /= num;}
	}
	printf("%d", answer);
}