// 6778 Which Alien?
// https://www.acmicpc.net/problem/6778
#include <stdio.h>

int main(){
	int antenna, eye;
	scanf("%d", &antenna);
	scanf("%d", &eye);
	if (antenna >= 3 && eye <= 4){printf("TroyMartian\n");}
	if (antenna <= 6 && eye >= 2){printf("VladSaturnian\n");}
	if (antenna <= 2 && eye <= 3){printf("GraemeMercurian\n");}
}