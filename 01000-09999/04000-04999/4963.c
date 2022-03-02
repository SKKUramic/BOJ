// 4963 섬의 개수
// https://www.acmicpc.net/problem/4963
#include <stdio.h>

int W, H;
int graph[52][52] = {0, };
int direction[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void DFS(int w, int h){
	if (graph[w][h] == 0){return;}
	graph[w][h] = 0;
	for (int i = 0; i < 8; i++){
		DFS(w + direction[i][0], h + direction[i][1]);
	}
	return;
}

int main(){
	int count;
	scanf("%d %d", &H, &W);
	while (W != 0 || H != 0){
		count = 0;
		for (int w = 1; w <= W; w++){
			for (int h = 1; h <= H; h++){
				scanf("%d", &graph[w][h]);
			}
		}
		for (int w = 1; w <= W; w++){
			for (int h = 1; h <= H; h++){
				if (graph[w][h] == 1){
					DFS(w, h);
					count++;
				}
			}
		}
		printf("%d\n", count);
		scanf("%d %d", &H, &W);
	}
}