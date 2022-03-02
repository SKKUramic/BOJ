// 2987 사과 나무
// https://www.acmicpc.net/problem/2987
#include <iostream>
#include <vector>
using namespace std;

struct Point{
	int x;
	int y;
};

Point Triangle[3];
Point Apple_tree[100];
int flag;

int CCW(Point p1, Point p2, Point p3){
	int x1 = p1.x, x2 = p2.x, x3 = p3.x;
	int y1 = p1.y, y2 = p2.y, y3 = p3.y;
	int ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	return ccw;
}

int CCW_bool(Point p1, Point p2, Point p3){
	int x1 = p1.x, x2 = p2.x, x3 = p3.x;
	int y1 = p1.y, y2 = p2.y, y3 = p3.y;
	int ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	if (ccw > 0) {return 1;}
	else if (ccw < 0) {return -1;}
	else {return 0;}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Triangle_area, apple_count, inside = 0;
	int C1, C2, C3;
	for (int i = 0; i < 3; i++){
		cin >> Triangle[i].x >> Triangle[i].y;
	}
	Triangle_area = CCW(Triangle[0], Triangle[1], Triangle[2]);
	if (Triangle_area < 0){
		flag = -1;
		Triangle_area = -Triangle_area;
	}
	else {
		flag = 1;
	}
	cin >> apple_count;
	for (int i = 0; i < apple_count; i++){
		cin >> Apple_tree[i].x >> Apple_tree[i].y;
		C1 = CCW(Triangle[0], Triangle[1], Apple_tree[i]);
		C2 = CCW(Triangle[1], Triangle[2], Apple_tree[i]);
		C3 = CCW(Triangle[2], Triangle[0], Apple_tree[i]);
		if ((flag > 0 && C1 >= 0 && C2 >= 0 && C3 >= 0) || (flag < 0 && C1 <= 0 && C2 <= 0 && C3 <= 0)){
			inside++;
		}
	}
	if (Triangle_area % 2 == 1){
		cout << Triangle_area / 2 << ".5\n";
	}
	else {
		cout << Triangle_area / 2 << ".0\n";
	}
	cout << inside;
}