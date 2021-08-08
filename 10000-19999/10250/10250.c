// 10250 ACM 호텔
#include <stdio.h>

int main(){
	int test, H, W, N, floor, room;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0){
			printf("%d%02d\n", H, N / H);
		}
		else {
			printf("%d%02d\n", N % H, N / H + 1);
		}
	}
}