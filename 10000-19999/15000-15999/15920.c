// 15920 선로에 마네킹이야!!
// https://www.acmicpc.net/problem/15920
#include <stdio.h>

char handle[10];

int main(){
	int len, second = 0, mannequin = 5;
	scanf("%d", &len);
	scanf("%s", handle);
	for (int i = 0; i < len; i++){
		if (second == 2){break;}
		if (handle[i] == 'W' && second < 2){ // 기다림
				second++;
		}
		else { // 레버를 움직임
			if (second == 0){ // A구역에서 레버를 움직임
				mannequin = mannequin == 5 ? 1 : 5;
			}
			else if (second == 1){ // B구역에서 레버를 움직임
				mannequin = 6;
			}
			else {} // C구역에서 레버를 움직임, 어차피 이 구역이 검사될 일이 없다.
		}
	}
	if (second < 2){mannequin = 0;} // C구역에 가기 전에 행동을 끝낼 경우 깔리는 마네킹은 없음
	printf("%d", mannequin);
}