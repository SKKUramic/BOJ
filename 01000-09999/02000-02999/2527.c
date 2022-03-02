// 2527 직사각형
#include <stdio.h>
#include <stdbool.h>

bool Make_square(int x1, int y1, int a1, int b1, int x2, int y2, int a2, int b2){
	// 필요없음ㅋㅋ 생각하는 게 더 빡세다
}

bool Line_contact(int x1, int y1, int a1, int b1, int x2, int y2, int a2, int b2){
	if (x1 == a2) {return true;}
	else if (a1 == x2) {return true;}
	else if (y1 == b2) {return true;}
	else if (b1 == y2) {return true;}
	else {return false;}
}

bool Point_contact(int x1, int y1, int a1, int b1, int x2, int y2, int a2, int b2){
	if (x1 == a2 && y1 == b2) {return true;}
	else if (x1 == a2 && b1 == y2) {return true;}
	else if (a1 == x2 && y1 == b2) {return true;}
	else if (a1 == x2 && b1 == y2) {return true;}
	else {return false;}
}

bool NO_contact(int x1, int y1, int a1, int b1, int x2, int y2, int a2, int b2){
	if (a1 < x2) {return true;}
	else if (a2 < x1) {return true;}
	else if (b1 < y2) {return true;}
	else if (b2 < y1) {return true;}
	else {return false;}
}

int main(){
	int x1, y1, a1, b1;
	int x2, y2, a2, b2;
	bool flags;
	for (int i = 0; i < 4; i++){
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &a1, &b1, &x2, &y2, &a2, &b2);
		if (NO_contact(x1, y1, a1, b1, x2, y2, a2, b2) == true){printf("d\n"); continue;}
		else if (Point_contact(x1, y1, a1, b1, x2, y2, a2, b2) == true){printf("c\n"); continue;}
		else if (Line_contact(x1, y1, a1, b1, x2, y2, a2, b2) == true){printf("b\n"); continue;}
		else {printf("a\n");}
	}
}