// 2254 감옥 건설
// https://www.acmicpc.net/problem/2254
// 중간에 탈출하지 마라 제발
#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll CCW(pll p1, pll p2, pll p3){
	ll x1 = p1.first, x2 = p2.first, x3 = p3.first;
	ll y1 = p1.second, y2 = p2.second, y3 = p3.second;
	ll ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	if (ccw < 0) {return -1;}
	else if (ccw > 0) {return 1;}
	else {return 0;} // 실제로는 안 쓰임
}

bool not_flag;
int point_count, point_stack_size;
vector<pll> point_list;
vector<int> point_stack;

bool cmp(pll a, pll b){
	long long ccw = CCW(point_list[0], a, b);
	if (ccw != 0) {return ccw > 0;}
	else {return a.first + a.second < b.first + b.second;}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int next_point, P1, P2, answer = 0;
	ll is_inside;
	pll P, Prison;
	cin >> point_count >> Prison.first >> Prison.second;
	for (int p = 0; p < point_count; p++){
		cin >> P.first >> P.second;
		point_list.push_back(P);
	}
	while (point_list.size() >= 3){
		not_flag = false;
		point_count = point_list.size();
		sort(point_list.begin(), point_list.end()); // 가장 왼쪽 아래에 있는 점을 찾기 위한 정렬
		sort(point_list.begin() + 1, point_list.end(), cmp);  // 첫 번째 점을 기준으로 각도순 정렬
		point_stack.push_back(0);
		point_stack.push_back(1);
		next_point = 2;
		while (next_point < point_count){
			while (point_stack.size() >= 2){
				P1 = point_stack.back();
				point_stack.pop_back();
				P2 = point_stack.back();
				if (CCW(point_list[P2], point_list[P1], point_list[next_point]) > 0){ 
					point_stack.push_back(P1);
					break;
				}
			}
			point_stack.push_back(next_point++);
		} // 이 과정을 거치면 가장 바깥의 볼록 다각형이 생김
		point_stack_size = point_stack.size();
		is_inside = CCW(point_list[point_stack[1]], point_list[point_stack[0]], Prison);
		for (int p = 0; p < point_stack_size; p++){ // 이 볼록 다각형 안에 감옥이 있는지 검사
			if (CCW(point_list[point_stack[(p + 1) % point_stack_size]], point_list[point_stack[p]], Prison) != is_inside){
				not_flag = true;
				break;
			}
		}
		while (!point_stack.empty()){ // 볼록 다각형에 사용되었던 점들을 전체 점들의 리스트에서 제거
			point_list.erase(point_list.begin() + point_stack.back());
			point_stack.pop_back();
		}
		if (not_flag == false){answer++;} // 실제로 볼록 다각형 안에 점이 있었을 경우
	}
	cout << answer;
}