// 14939 불 끄기
// https://www.acmicpc.net/problem/14939
#include <stdio.h>

char bulb[10][10], copy[10][10];

void push(int y, int x){
	copy[y][x] = copy[y][x] == '#' ? 'O' : '#';
	if (y > 0){copy[y - 1][x] = copy[y - 1][x] == '#' ? 'O' : '#';}
	if (y < 9){copy[y + 1][x] = copy[y + 1][x] == '#' ? 'O' : '#';}
	if (x > 0){copy[y][x - 1] = copy[y][x - 1] == '#' ? 'O' : '#';}
	if (x < 9){copy[y][x + 1] = copy[y][x + 1] == '#' ? 'O' : '#';}
	return;
}

int main(){
	int answer = 9999999, count;
	for (int i = 0; i < 10; i++){
		scanf("%s", bulb[i]);
	}
	for (int click = 0; click < (1 << 10); click++){ // 여기서 비트마스킹을 씀
		count = 0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				copy[i][j] = bulb[i][j];
			}
		}
		for (int i = 0; i < 10; i++){
			if ((click & (1 << i)) != 0){
				count++;
				push(0, i);
			}
		}
		for (int i = 1; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (copy[i - 1][j] == 'O'){
					count++;
					push(i, j);
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < 10; i++){
			if (copy[9][i] == 'O'){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			if (answer > count){answer = count;}
		}
	}
	if (answer == 9999999){printf("-1");}
	else {printf("%d", answer);}
}