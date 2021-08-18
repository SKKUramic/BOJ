// 3546 Headshot
// https://www.acmicpc.net/problem/3546
#include <stdio.h>
#include <string.h>

int main(){
	int dead = 0, alive = 0, zero_count = 0;
	char russian[101];
	scanf("%s", russian);
	int len = strlen(russian);
	for (int i = 0; i < len; i++){
		if (russian[i] == '0'){zero_count++;}
		if (i == len - 1){
			if (russian[i] == '0'){
				if (russian[0] == '0'){
					alive++;
				}
				else{
					dead++;
				}
			}
		}
		else {
			if (russian[i] == '0'){
				if (russian[i + 1] == '0'){
					alive++;
				}
				else{
					dead++;
				}
			}
		}
	}
	// 바로 쏴서 살 확률: alive / (dead + alive)
	// 돌리고 쏴서 살 확률: zero_count / len
	if (alive * len == zero_count * (dead + alive)){
		printf("EQUAL");
	}
	else if (alive * len > zero_count * (dead + alive)){
		printf("SHOOT");
	}
	else {
		printf("ROTATE");
	}
}