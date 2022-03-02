// 15898 피아의 아틀리에 ~신비한 대회의 연금술사~
// https://www.acmicpc.net/problem/15898
// choose 함수들은 순열을 뽑는 것과 같은 방식으로 동작되어야 한다
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char material_color[10][4][4][4]; // [재료의 순서][시계 방향으로 90 * i도 돌림][y][x]
int material_quality[10][4][4][4]; // [재료의 순서][시계 방향으로 90 * i도 돌림][y][x]
char cauldron_color[5][5];
int cauldron_quality[5][5];
int material_count;
int highest_quality_bomb = -10000000;

void init(){
	for (int a = 0; a < 5; a++){
		for (int b = 0; b < 5; b++){
			cauldron_quality[a][b] = 0;
		}
	}
	for (int a = 0; a < 5; a++){
		for (int b = 0; b < 5; b++){
			cauldron_color[a][b] = 'W';
		}
	}
	return;
}

void print_cauldron(int arr1[][5], char arr2[][5]){ // 디버그용
	for (int a = 0; a < 5; a++){
		for (int b = 0; b < 5; b++){
			printf("%d%c ", arr1[a][b], arr2[a][b]);
		}
		printf("\n");
	}
	return;
}

void make_bomb(int use[][3]){
	int dx, dy, material, rotation, score;
	int color_score[4] = {0, }; // R, B, G, Y
	init();
	for (int idx = 0; idx < 3; idx++){
		material = use[idx][0]; rotation = use[idx][1]; dx = use[idx][2] / 2; dy = use[idx][2] % 2; // 미리 지정된 재료, 회전, 대입 위치로 계산함
		for (int y = 0; y < 4; y++){
			for (int x = 0; x < 4; x++){
				if (material_color[material][rotation][y][x] != 'W'){ // 재료의 색깔이 하얀색이 아니면 색깔이 변화함
					cauldron_color[y + dy][x + dx] = material_color[material][rotation][y][x];
				}
				cauldron_quality[y + dy][x + dx] += material_quality[material][rotation][y][x];
				if (cauldron_quality[y + dy][x + dx] < 0) {cauldron_quality[y + dy][x + dx] = 0;} // 재료의 품질이 0 미만이면 0으로 되돌림
				else if (cauldron_quality[y + dy][x + dx] > 9) {cauldron_quality[y + dy][x + dx] = 9;} // 재료의 품질이 9 초과이면 9로 되돌림
			}
		}
	}
	for (int y = 0; y < 5; y++){
		for (int x = 0; x < 5; x++){
			if (cauldron_color[y][x] == 'R'){
				color_score[0] += cauldron_quality[y][x];
			}
			else if (cauldron_color[y][x] == 'B'){
				color_score[1] += cauldron_quality[y][x];
			}
			else if (cauldron_color[y][x] == 'G'){
				color_score[2] += cauldron_quality[y][x];
			}
			else if (cauldron_color[y][x] == 'Y'){
				color_score[3] += cauldron_quality[y][x];
			}
		}
	}
	score = 7 * color_score[0] + 5 * color_score[1] + 3 * color_score[2] + 2 * color_score[3];
	if (highest_quality_bomb < score) {
		highest_quality_bomb = score;
	}
	return;
}

void choose_point(int use[][3], int count){
	if (count == 3){
		make_bomb(use);// 함수 보내기
		return;
	}
	for (int point = 0; point < 4; point++){
		use[count][2] = point;
		choose_point(use, count + 1);
	}
	return;
}

void choose_rotate(int use[][3], int count){
	if (count == 3){
		choose_point(use, 0);// 함수 보내기
		return;
	}
	for (int rotate = 0; rotate < 4; rotate++){
		use[count][1] = rotate;
		choose_rotate(use, count + 1);
	}
	return;
}

void choose_materials(int use[][3], int count){
	if (count == 3){
		choose_rotate(use, 0); // 함수 보내기
		return;
	}
	// materials번째 재료를 사용할 경우
	for (int material = 0; material < material_count; material++){
		if (use[0][0] == material || use[1][0] == material){
			continue;
		}
		use[count][0] = material;
		choose_materials(use, count + 1);
		use[count][0] = -1;
	}
	return;
}

int main(){
	int use_material[3][3] = {{-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}};
	char temp_arr[10];
	scanf("%d", &material_count);
	for (int i = 0; i < material_count; i++){
		for (int a = 0; a < 4; a++){
			for (int b = 0; b < 4; b++){
				scanf("%d", &material_quality[i][0][a][b]);
				material_quality[i][1][3 - b][a] = material_quality[i][0][a][b];
				material_quality[i][2][3 - a][3 - b] = material_quality[i][0][a][b];
				material_quality[i][3][b][3 - a] = material_quality[i][0][a][b];
			}
		}
		for (int a = 0; a < 4; a++){
			scanf("\n%c %c %c %c", &temp_arr[0], &temp_arr[1], &temp_arr[2], &temp_arr[3]);
			for (int b = 0; b < 4; b++){
				material_color[i][0][a][b] = temp_arr[b];
				material_color[i][1][3 - b][a] = material_color[i][0][a][b];
				material_color[i][2][3 - a][3 - b] = material_color[i][0][a][b];
				material_color[i][3][b][3 - a] = material_color[i][0][a][b];
			}
		}
	}
	choose_materials(use_material, 0);
	printf("%d", highest_quality_bomb);
}