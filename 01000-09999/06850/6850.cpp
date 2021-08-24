// 6850 Cows
// https://www.acmicpc.net/problem/6850
// 볼록 다각형을 이루는 점들을 이용해 넓이를 구하는 문제
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

int point_count, answer_len;
pll answer_list[10002];
pll point_list[10002];
stack<pll> point_stack;

bool cmp(pll a, pll b){
	long long ccw = CCW(point_list[0].first, point_list[0].second, a.first, a.second, b.first, b.second);
	if (ccw != 0) {return ccw > 0;}
	else {return a.first + a.second < b.first + b.second;}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll area = 0;
	pll P, P1, P2;
	cin >> point_count;
	for (int p = 0; p < point_count; p++){
		cin >> P.first >> P.second;
		point_list[p] = P;
	}
	sort(point_list, point_list + point_count);
	sort(point_list + 1, point_list + point_count, cmp); 
	point_stack.push(point_list[0]);
	point_stack.push(point_list[1]);
	int next_point = 2;
	while (next_point < point_count){
		while (point_stack.size() >= 2){
			P1 = point_stack.top();
			point_stack.pop();
			P2 = point_stack.top();
			if (CCW(P2.first, P2.second, P1.first, P1.second, point_list[next_point].first, point_list[next_point].second) > 0){ 
				point_stack.push(P1);
				break;
			}
		}
		point_stack.push(point_list[next_point++]);
	}
	answer_len = point_stack.size();
	for (int i = point_stack.size() - 1; i >= 0; i--){
		answer_list[i] = point_stack.top();
		point_stack.pop();
	}
	P = answer_list[0];
	for (int p = 1; p < answer_len - 1; p++){
		area += CCW(P.first, P.second, answer_list[p].first, answer_list[p].second, answer_list[p + 1].first, answer_list[p + 1].second);
	}
	if (area < 0){area = -area;}
	cout << (area / 2) / 50;
}