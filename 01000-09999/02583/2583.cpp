// 2583 영역 구하기
// https://www.acmicpc.net/problem/2583
#include <stdio.h>
#include <algorithm>

int W, H, Square, area_idx = 0;
int Graph[102][102] = {0, };
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int area[5001] = {0, }; // 아무리 그래도 5000개 아닐까

void Fill_Graph(int w, int h){
	if (Graph[w][h] == 1){return;}
	Graph[w][h] = 1;
	area[area_idx]++;
	for (int i = 0; i < 4; i++){
		Fill_Graph(w + direction[i][0], h + direction[i][1]);
	}
	return;
}

int main(){
	int x1, y1, x2, y2, count = 0;
	scanf("%d %d %d", &W, &H, &Square);
	for (int w = 0; w <= W + 1; w++){
		Graph[w][0] = 1; Graph[w][H + 1] = 1;
	}
	for (int h = 0; h <= H + 1; h++){
		Graph[0][h] = 1; Graph[W + 1][h] = 1;
	}
	for (int s = 0; s < Square; s++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1++; y1++; x2++; y2++;
		for (int x = x1; x < x2; x++){
			for (int y = y1; y < y2; y++){
				Graph[y][x] = 1;
			}
		}
	}
	for (int w = 1; w <= W; w++){
		for (int h = 1; h <= H; h++){
			if (Graph[w][h] == 0){
				Fill_Graph(w, h);
				count++;
				area_idx++;
			}
		}
	}
	std::sort(area, area + area_idx);
	printf("%d\n", count);
	for (int i = 0; i < area_idx; i++){
		printf("%d ", area[i]);
	}
}