// 6439 교차
// https://www.acmicpc.net/problem/6439
#include <iostream>
#include <utility>
using namespace std;

#define MAX 1200000000
typedef long long int lli;

int N;
pair<lli, lli> square[4];
pair<lli, lli> line[2];

bool is_Inside(lli left, lli right, lli bottom, lli top){ // 점 하나라도 사각형 안에 있는지 검사
	int count = 0;
	for (int i = 0; i < 2; i++){
		if ((left < line[i].first && line[i].first < right) && (bottom < line[i].second && line[i].second < top)){ // 선분의 끝점이 사각형 내부 혹은 변에 위치해 있을 경우
			count++;
		}
	}
	if (count == 2){return true;}
	else {return false;}
}

int CCW(pair<lli, lli> p1, pair<lli, lli> p2, pair<lli, lli> P){
	lli ccw = p1.first * p2.second + p2.first * P.second + P.first * p1.second - (p2.first * p1.second + P.first * p2.second + p1.first * P.second);
	if (ccw < 0){return -1;} // 반시계
	else if (ccw > 0) {return 1;} // 시계
	else {return 0;} // 일직선
}

bool Is_intersect(pair<lli, lli> p1, pair<lli, lli> p2, pair<lli, lli> p3, pair<lli, lli> p4){
	int CCW12_3, CCW12_4, CCW34_1, CCW34_2;
	CCW12_3 = CCW(p1, p2, p3);
	CCW12_4 = CCW(p1, p2, p4);
	CCW34_1 = CCW(p3, p4, p1);
	CCW34_2 = CCW(p3, p4, p2);
	if (CCW12_3 * CCW12_4 <= 0 && CCW34_1 * CCW34_2 <= 0){
		if (CCW12_3 * CCW12_4 == 0 && CCW34_1 * CCW34_2 == 0){ // 일직선 위에 4개의 점이 모두 있을 경우
			if (p1 > p2){swap(p1, p2);}
			if (p3 > p4){swap(p3, p4);}
			if (p2 >= p3 && p1 <= p4){return true;}
			else {return false;}
		}
		else { // 일직선이 아니며, 두 선분은 교차함
			return true;
		}
	}
	else { //교차 안 함ㅅㄱ
		return false;
	}
}

bool Is_meet(){
	int count = 0;
	pair<lli, lli> p1, p2, p3, p4;
	p3 = line[0];
	p4 = line[1];
	for (int i = 0; i < 4; i++){
		p1 = square[i];
		p2 = square[(i + 1) % 4];
		if (p1.first == p3.first && p1.second == p3.second){ // 그 도형의 점과 동일한 위치에 있을 경우
			return true;
		}
		else if (Is_intersect(p3, p3, p1, p2) == true){ // 그 점이 선 위에 있을 경우
			return true;
		}
		if (Is_intersect(p1, p2, p3, p4) == true){count++;} // 교차할 경우 count 추가
	}
	if (count == 0){ // 선분과 사각형의 교점이 하나도 없을 경우
		return false;
	}
	else { // 선분과 사각형의 교점이 하나라도 있을 경우
		return true;
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x_left, x_right, y_bottom, y_top, intersect_count = 0;
	cin >> N;
	for (int x = 0; x < N; x++){
		for (int i = 0; i < 2; i++){
			cin >> line[i].first >> line[i].second;
		}
		cin >> x_left >> y_top >> x_right >> y_bottom;
		if (x_left > x_right){swap(x_left, x_right);}
		if (y_bottom > y_top){swap(y_bottom, y_top);}
		if (is_Inside(x_left, x_right, y_bottom, y_top) == true){
			cout << "T\n";
			continue;
		}
		square[0].first = x_left; square[0].second = y_bottom;
		square[1].first = x_right; square[1].second = y_bottom;
		square[2].first = x_right; square[2].second = y_top;
		square[3].first = x_left; square[3].second = y_top;
		if (Is_meet()){
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}
	}
}