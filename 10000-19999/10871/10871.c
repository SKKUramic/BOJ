// 10871 X보다 작은 수
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n, x, y;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++){
		scanf("%d", &y);
		if (y < x){
			printf("%d ", y);
		}
	}
}