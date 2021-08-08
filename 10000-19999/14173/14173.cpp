// 14173 Square Pasture
// https://www.acmicpc.net/problem/14173
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int x1_1, x1_2, y1_1, y1_2, x2_1, x2_2, y2_1, y2_2;
	int height, width, side;
	scanf("%d %d %d %d", &x1_1, &y1_1, &x1_2, &y1_2);
	scanf("%d %d %d %d", &x2_1, &y2_1, &x2_2, &y2_2);
	height = max(max(x1_2 - x1_1, x2_2 - x1_1), max(x1_2 - x2_1, x2_2 - x2_1));
	width = max(max(y1_2 - y1_1, y2_2 - y1_1), max(y1_2 - y2_1, y2_2 - y2_1));
	side = max(height, width);
	printf("%d", side * side);
}