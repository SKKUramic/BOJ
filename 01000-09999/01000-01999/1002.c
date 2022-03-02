// 1002 터렛
#include <stdio.h>

int main(){
	int test, x1, x2, y1, y2, r1, r2;
	int X, Y, R, minr;
	scanf("%d", &test);
	for (int i = 0; i < test; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		X = (x2 - x1) * (x2 - x1);
		Y = (y2 - y1) * (y2 - y1);
		R = (r1 + r2) * (r1 + r2);
		minr = r1 < r2 ? r1 : r2;
		// printf("%d %d %d\n", X, Y, R);
		if (x1 == x2 && y1 == y2){ // 두 원의 중심이 같을 때
			if (r1 == r2){ // 반지름이 서로 같음, 즉 두 원이 같은 원
				printf("-1\n");
			}
			else { // 반지름이 서로 다름
				printf("0\n");
			}
		}
		else if (X + Y == (r2 - r1) * (r2 - r1)){ // 원이 다른 원 안에 교점 하나로 들어가 있는 경우
			printf("1\n");
		}
		else if (X + Y < (r2 - r1) * (r2 - r1)){ // 원이 다른 원 안에 교점 없이 들어가있는 경우
			printf("0\n");
		}
		else if (X + Y < R){ // 두 원이 겹쳐져 있을 경우
			printf("2\n");
		}
		else if (X + Y == R){ // 두 원의 교차점이 하나일 경우
			printf("1\n");
		}
		else { // 두 원이 만나지 않을 경우
			printf("0\n");
		}
	}
}