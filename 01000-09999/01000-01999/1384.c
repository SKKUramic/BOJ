// 1384 메시지
// https://www.acmicpc.net/problem/1384
#include <stdio.h>

char children[21][61];
char message[21][21];

int main(){
	int group_number = 0, student, nasty_count = 0;
	scanf("%d", &student);
	while (student != 0){
		group_number++;
		nasty_count = 0;
		printf("Group %d\n", group_number);
		for (int i = 0; i < student; i++){
			scanf("%s", children[i]);
			for (int j = 0; j < student - 1; j++){
				scanf(" %c", &message[i][j]);
			}
		}
		for (int a = 0; a < student; a++){
			for (int b = 0; b < student - 1; b++){
				if (message[a][b] == 'N'){
					nasty_count++;
					printf("%s was nasty about %s\n", children[(a - (b + 1) + student) % student], children[a]);
				}
			}
		}
		if (nasty_count == 0){
			printf("Nobody was nasty\n");
		}
		printf("\n");
		scanf("%d", &student);
	}
}