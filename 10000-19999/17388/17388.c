// 17388 와글와글 숭고한
// https://www.acmicpc.net/problem/17388
#include <stdio.h>

int main(){
	int Soongsil, Korea, Hanyang;
	scanf("%d %d %d", &Soongsil, &Korea, &Hanyang);
	if (Soongsil + Korea + Hanyang >= 100){printf("OK");}
	else {
		if (Soongsil < Korea){
			if (Soongsil < Hanyang){
				printf("Soongsil");
			}
			else {
				printf("Hanyang");
			}
		}
		else {
			if (Korea < Hanyang){
				printf("Korea");
			}
			else {
				printf("Hanyang");
			}
		}
	}
}