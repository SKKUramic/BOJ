// 2292 벌집
#include <stdio.h>

int main(){
	int room_num, count = 1, go = 1;
	scanf("%d", &room_num);
	while(room_num > go){
		go += 6 * count;
		count++;
	}
	printf("%d", count);
}