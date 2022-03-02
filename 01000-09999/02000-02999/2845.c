// 2845 파티가 끝나고 난 뒤
#include <stdio.h>

int main(){
	int room, people, all;
	int p1, p2, p3, p4, p5;
	scanf("%d %d", &room, &people);
	all = room * people;
	scanf("%d %d %d %d %d", &p1, &p2, &p3, &p4, &p5);
	printf("%d %d %d %d %d", p1 - all, p2 - all, p3 - all, p4 - all, p5 - all);
}