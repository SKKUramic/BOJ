// 11758 CCW
// https://www.acmicpc.net/problem/11758
// 외적 문제입니다. 몰라도 푸는 건 가능하지만 알아내기 좀 힘들 수 있습니다.
#include <stdio.h>

int Px[3], Py[3];

int CCW(){ // 직선을 구한 후, 그 직선 위에 있는지 아래에 있는지 확인하는 공식입니다. 기울기의 부호에 따라 결과가 달라지며 외적 공식을 이용하지 않고 가능합니다.
	if ((Py[1] - Py[0]) * (Px[2] - Px[0]) + Py[0] * (Px[1] - Px[0]) > Py[2] * (Px[1] - Px[0])){
		// (y2 - y1)(x3 - x1) + y1(x2-x1) > y3(x2 - x1), 시계입니다.
		return -1;
	}
	else if ((Py[1] - Py[0]) * (Px[2] - Px[0]) + Py[0] * (Px[1] - Px[0]) < Py[2] * (Px[1] - Px[0])){
		// (y2 - y1)(x3 - x1) + y1(x2-x1) < y3(x2 - x1), 반시계입니다.
		return 1;
	}
	else {
		// 세 점이 한 직선 위에 있습니다.
		return 0;
	}
}

int CCW_Product(){ // 외적 공식을 이용한 것입니다. https://www.acmicpc.net/blog/view/27
	int temp = (Px[1] - Px[0]) * (Py[2] - Py[0]) - (Py[1] - Py[0]) * (Px[2] - Px[0]);
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0){
		return -1;
	}
	else {
		return 0;
	}
}

int main(){
	for (int i = 0; i < 3; i++){
		scanf("%d %d", &Px[i], &Py[i]);
	}
	printf("%d", CCW());
	//printf("%d", CCW_Product());
}