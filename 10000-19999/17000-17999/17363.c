// 17363 우유가 넘어지면?
// https://www.acmicpc.net/problem/17363
#include <stdio.h>

char picture[101][101];

char AYA(char c){
	if (c == '-'){return '|';}
	else if (c == '|') {return '-';}
	else if (c == '/') {return '\\';}
	else if (c == '\\') {return '/';}
	else if (c == '^') {return '<';}
	else if (c == '<') {return 'v';}
	else if (c == 'v') {return '>';}
	else if (c == '>') {return '^';}
	else {return c;}
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		scanf("%s", picture[i]);
	}
	for (int i = M - 1; i >= 0; i--){
		for (int j = 0; j < N; j++){
			printf("%c", AYA(picture[j][i]));
		}
		printf("\n");
	}
}