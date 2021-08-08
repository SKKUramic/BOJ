// 10026 적록색약
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
char picture[101][101];
char picture_RGblindness[101][101];

void print(){ // 정상인이 본 그림(디버그용)
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%c", picture[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void print_RGblindness(){ // 적록색약이 본 그림(디버그용)
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%c", picture_RGblindness[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void seeing_by_RGblindness(){ // 적록색약이 본 그림을 편하게 그림
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (picture_RGblindness[i][j] == 'R' || picture_RGblindness[i][j] == 'G'){
				picture_RGblindness[i][j] = '?';
			}
		}
	}
	return;
}

void Not_RGblindness_DFS(int x, int y, char color){
	picture[x][y] = 'X';
	if (x > 0 && picture[x - 1][y] == color){
		Not_RGblindness_DFS(x - 1, y, color);
	}
	if (x < N - 1 && picture[x + 1][y] == color){
		Not_RGblindness_DFS(x + 1, y, color);
	}
	if (y > 0 && picture[x][y - 1] == color){
		Not_RGblindness_DFS(x, y - 1, color);
	}
	if (y < N - 1 && picture[x][y + 1] == color){
		Not_RGblindness_DFS(x, y + 1, color);
	}
	return;
}

void RGblindness_DFS(int x, int y, char color){
	picture_RGblindness[x][y] = 'X';
	if (x > 0 && picture_RGblindness[x - 1][y] == color){
		RGblindness_DFS(x - 1, y, color);
	}
	if (x < N - 1 && picture_RGblindness[x + 1][y] == color){
		RGblindness_DFS(x + 1, y, color);
	}
	if (y > 0 && picture_RGblindness[x][y - 1] == color){
		RGblindness_DFS(x, y - 1, color);
	}
	if (y < N - 1 && picture_RGblindness[x][y + 1] == color){
		RGblindness_DFS(x, y + 1, color);
	}
	return;
}

// 두 DFS 함수를 합칠 수 있겠지만 귀찮음ㅎㅎ

int main(){
	int not_RGblindness_count = 0, RGblindness_count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", picture[i]);
		memmove(picture_RGblindness[i], picture[i], sizeof(char) * N);
	}
	seeing_by_RGblindness();
	//print();
	//print_RGblindness();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (picture[i][j] != 'X'){
				Not_RGblindness_DFS(i, j, picture[i][j]);
				not_RGblindness_count++;
			}
			if (picture_RGblindness[i][j] != 'X'){
				RGblindness_DFS(i, j, picture_RGblindness[i][j]);
				RGblindness_count++;
			}
		}
	}
	printf("%d %d", not_RGblindness_count, RGblindness_count);
}