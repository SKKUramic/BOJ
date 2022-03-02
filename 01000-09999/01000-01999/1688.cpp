// 1688 지민이의 테러
// https://www.acmicpc.net/problem/1688
#include <iostream>
#include <utility>
using namespace std;

#define MAX 1200000000
typedef long long int lli;

int N, X, Y;
pair<lli, lli> point[10001];
pair<lli, lli> people[3];

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
	return 0;
}

bool Is_inside_barrier(int people_idx){
	int count = 0;
	pair<lli, lli> p1, p2, p3, p4;
	p3 = people[people_idx];
	p4.first = MAX; p4.second = people[people_idx].second + 1; // 사실상 일직선인 선분을 만들기 위해
	for (int i = 0; i < N; i++){
		p1 = point[i];
		p2 = point[(i + 1) % N];
		if (p1.first == p3.first && p1.second == p3.second){ // 그 도형의 점과 동일한 위치에 있을 경우
			return true;
		}
		else if (Is_intersect(p3, p3, p1, p2) == true){ // 그 점이 선 위에 있을 경우
			return true;
		}
		if (Is_intersect(p1, p2, p3, p4) == true){count++;} // 교차할 경우 count 추가
	}
	if (count % 2 == 1){return true;} // 교차하는 선분이 홀수개일 경우 도형 안에 있음
	else {return false;} // 짝수개일 경우 도형 밖에 있음
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> X >> Y;
		point[i].first = X;
		point[i].second = Y;
	}
	for (int i = 0; i < 3; i++){
		cin >> X >> Y;
		people[i].first = X;
		people[i].second = Y;
		if (Is_inside_barrier(i)){
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}