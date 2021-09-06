// 12927 배수 스위치
// https://www.acmicpc.net/problem/12927
#include <stdio.h>
#include <string.h>

char bulb[1001];

int main(){
	int len, on_count = 0, switch_count = 0;
	scanf("%s", bulb);
	len = strlen(bulb);
	for (int i = 0; i < len; i++){
		if (bulb[i] == 'Y'){on_count++;}
	}
	for (int a = 0; a < len; a++){
		if (on_count == 0){break;}
		if (bulb[a] == 'Y'){
			for (int b = a; b < len; b += (a + 1)){
				if (bulb[b] == 'Y'){
					on_count--;
					bulb[b] = 'N';
				}
				else {
					on_count++;
					bulb[b] = 'Y';
				}
			}
			switch_count++;
		}
	}
	if (on_count != 0){printf("-1");}
	else {printf("%d", switch_count);}
}