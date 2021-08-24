// 1708 볼록 껍질
// https://www.acmicpc.net/problem/1708
// https://coder-in-war.tistory.com/entry/개념-45-볼록-껍질Convex-Hull(kim.svadoz님)에게 많이 배웠습니다
#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll CCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	ll ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	return ccw;
}

int point_count;
pll point_list[100002];
stack<pll> point_stack;

bool cmp(pll a, pll b){
	long long ccw = CCW(point_list[0].first, point_list[0].second, a.first, a.second, b.first, b.second);
	if (ccw != 0) {return ccw > 0;} // 각도가 작은 순서대로 넣음, 첫 번째 점과 두 점이 만드는 ccw 값이 0보다 크면 원하는 순서대로 정렬된 것이다 
	else {return a.first + a.second < b.first + b.second;} // 두 점이 각도가 같다면 가까운 점부터 정렬
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pll P, P1, P2;
	cin >> point_count;
	for (int p = 0; p < point_count; p++){
		cin >> P.first >> P.second;
		point_list[p] = P;
	}
	sort(point_list, point_list + point_count); // 첫 번째 점은 y좌표가 가장 작은 점들 중 x좌표가 가장 작은 점
	sort(point_list + 1, point_list + point_count, cmp); // 첫 번째 점을 기준으로 반시계 방향으로 돌아가며, 가장 각도가 작은 순서대로 정렬됨(y좌표가 같으면 가까운 점부터 정렬)
	point_stack.push(point_list[0]);
	point_stack.push(point_list[1]); // 두 점을 스택에 넣고 시작
	int next_point = 2;
	while (next_point < point_count){
		while (point_stack.size() >= 2){ // 아무리 못 해도 두 점은 있어야 CCW 알고리즘을 사용할 수 있음
			P1 = point_stack.top();
			point_stack.pop();
			P2 = point_stack.top();
			if (CCW(P2.first, P2.second, P1.first, P1.second, point_list[next_point].first, point_list[next_point].second) > 0){ 
				// 지금 검사하는 점이 만들고 있는 볼록 다각형 안에 있다면
				point_stack.push(P1);
				break;
			}
			// 만약 볼록 다각형 바깥에 있다면 직전의 점을 스택에서 제외함
		}
		point_stack.push(point_list[next_point++]);
	}
	cout << point_stack.size();
	
}