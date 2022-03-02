// 5026 박사 과정
// https://www.acmicpc.net/problem/5026
#include <stdio.h>
#include <string.h>

int main(){
	int N, a, b;
	char problem[20];
	scanf("%d", &N);
	while (N-- > 0){
		scanf("%s", problem);
		if (problem[1] == '='){
			printf("skipped\n");
		}
		else {
			a = 0; b = 0;
			int i;
			for (i = 0; problem[i] != '+'; i++){
				a = a * 10 + (problem[i] - '0');
			}
			i++;
			for (; i < strlen(problem); i++){
				b = b * 10 + (problem[i]- '0');
			}
			printf("%d\n", a + b);
		}
	}
}