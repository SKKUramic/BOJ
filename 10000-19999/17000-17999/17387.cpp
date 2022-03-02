// 17386 선분 교차 2
// https://www.acmicpc.net/problem/17386
// CCW 알고리즘을 이용한 문제이며, 강화판입니다.
// pair의 대소 비교를 이용하여 네 점이 한 직선 위에 있을 때를 대처합시다.
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

/*
void swap(long long int *a, long long int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}*/

int CCW(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
	long long int ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	if (ccw < 0){return -1;}
	else if (ccw > 0) {return 1;}
	else {return 0;}
}

int main(){
	int CCW12_3, CCW12_4, CCW34_1, CCW34_2;
	pair<long long int, long long int> p1, p2, p3, p4;
	//long long int A12, B12, C12, A34, B34, C34; // 원래는 직선의 방정식을 이용해 풀려고 했는데 반례를 못 찾아서 포기함
	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	cin >> p3.first >> p3.second >> p4.first >> p4.second;
	CCW12_3 = CCW(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
	CCW12_4 = CCW(p1.first, p1.second, p2.first, p2.second, p4.first, p4.second);
	CCW34_1 = CCW(p3.first, p3.second, p4.first, p4.second, p1.first, p1.second);
	CCW34_2 = CCW(p3.first, p3.second, p4.first, p4.second, p2.first, p2.second);
	if (CCW12_3 * CCW12_4 == 0 && CCW34_1 * CCW34_2 == 0){ // 네 점이 한 직선 위에 있을 때
		if (p1 > p2){
			swap(p1, p2);
		}
		if (p3 > p4){
			swap(p3, p4);
		}
		if (p2 >= p3 && p1 <= p4){
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else if (CCW12_3 * CCW12_4 <= 0 && CCW34_1 * CCW34_2 <= 0){
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}