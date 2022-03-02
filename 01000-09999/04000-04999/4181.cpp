// 4181 Convex Hull
// https://www.acmicpc.net/problem/4181
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> point_list;

ll CCW(pll p1, pll p2, pll p3){
	ll x1 = p1.first, x2 = p2.first, x3 = p3.first;
	ll y1 = p1.second, y2 = p2.second, y3 = p3.second;
	ll ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	return ccw;
}

bool cmp(pll a, pll b){
	ll ccw = CCW(point_list[0], a, b);
	if (ccw != 0) {return ccw > 0;}
	else {return a.first + a.second < b.first + b.second;} // 단, 정렬 후 첫번째 점과 마지막 점의 직선에 다른 점도 포함되어 있을 경우에는 그 구간에 한하여 역순으로 정렬되어 있음
}

int main(){
	char C;
	int N, count = 0, idx = 0;
	pll P;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> P.first >> P.second >> C;
		if (C == 'Y'){
			point_list.push_back(P);
			count++;
		}
	}
	sort(point_list.begin(), point_list.end());
	sort(point_list.begin() + 1, point_list.end(), cmp);
	for (int i = count - 1; i > 0; i--){ // 마지막 점부터 검사함
		if (CCW(point_list[i - 1], point_list[i], point_list[0]) != 0){
			// 첫번째 점과 마지막 점으로 만들어진 일직선 위의 모든 점들의 순서를 뒤집어야 함(첫번째 점 제외)
			idx = i;
			break;
		}
	}
	reverse(point_list.begin() + idx, point_list.end());
	cout << count << '\n';
	for (int c = 0; c < count; c++){
		cout << point_list[c].first << ' ' << point_list[c].second << '\n';
	}
}