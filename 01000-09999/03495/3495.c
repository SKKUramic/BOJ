// 3495 아스키 도형
// https://www.acmicpc.net/problem/3495
// '/'와 '\'의 갯수를 세어, 짝수일 때의 점은 도형 바깥의 점이고 홀수일 때의 점은 도형 안의 점임을 파악하자.
#include <stdio.h>

char sqaure[101][101];

int main(){
	int height, width;
	int slash_count = 0, area = 0;
	scanf("%d %d", &height, &width);
	for (int h = 0; h < height; h++){
		scanf("%s", sqaure[h]);
	}
	for (int h = 0; h < height; h++){
		for (int w = 0; w < width; w++){
			if (sqaure[h][w] == '/' || sqaure[h][w] == '\\'){ // 도형 안인지 밖인지 구분하기 위해 센다
				slash_count++;
			}
			else if (sqaure[h][w] == '.'){
				if (slash_count % 2 == 1){ // 도형 안의 점일 경우
					area++;
				}
			}
		}
	}
	area += slash_count / 2;
	printf("%d", area);
}