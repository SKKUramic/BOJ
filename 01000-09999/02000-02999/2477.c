// 2447 참외밭
#include <stdio.h>
#include <stdlib.h>

int side[6][2] = {0, };

int main(){
	int melon, direction, side_length, small_area = 1, big_area = 1, garo_small, sero_small;
	int garo_max = -1, sero_max = -1, garo_index, sero_index;
	scanf("%d", &melon);
	for (int i = 0; i < 6; i++){
		scanf("%d %d", &side[i][0], &side[i][1]);
		if (side[i][0] <= 2 && garo_max < side[i][1]){
			garo_max = side[i][1];
			garo_index = i;
		}
		if (side[i][0] > 2 && sero_max < side[i][1]){
			sero_max = side[i][1];
			sero_index = i;
		}
	}
	garo_small = abs(side[(garo_index + 5) % 6][1] - side[(garo_index + 7) % 6][1]);
	sero_small = abs(side[(sero_index + 5) % 6][1] - side[(sero_index + 7) % 6][1]);
	//printf("%d %d %d %d\n", garo_index, sero_index, garo_small, sero_small);
	small_area = garo_small * sero_small;
	big_area = side[garo_index][1] * side[sero_index][1];
	printf("%d", melon * (big_area - small_area));
}