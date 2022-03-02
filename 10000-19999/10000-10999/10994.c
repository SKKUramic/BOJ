// 10994 별 찍기 - 19
#include <stdio.h>

char star_map[401][401];

void init(int n){
	for (int i = 0; i <= 4 * n; i++){
		for (int j = 0; j <= 4 * n; j++){
			star_map[i][j] = ' ';
		}
	}
	return;
}

void printing_star(int n){
	for (int i = 0; i < 4 * n - 3; i++){
		for (int j = 0; j < 4 * n - 3; j++){
			printf("%c", star_map[i][j]);
		}
		printf("\n");
	}
	return;
}

void pointing_star(int n, int x, int y){
	if (n == 1){
		star_map[x][y] = '*';
		return;
	}
	int len = 4 * n - 3;
	for (int i = x; i < x + len; i++){
		star_map[i][y] = '*';
		star_map[i][y + len - 1] = '*';
	}
	for (int i = y; i < y + len; i++){
		star_map[x][i] = '*';
		star_map[x + len - 1][i] = '*';
	}
	pointing_star(n - 1, x + 2, y + 2);
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	init(n);
	pointing_star(n, 0, 0);
	printing_star(n);
}