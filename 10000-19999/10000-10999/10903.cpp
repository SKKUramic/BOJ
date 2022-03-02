// 10903 Wall construction
// https://www.acmicpc.net/problem/10903
// 7420 맹독 방벽과 출력 형식만 다를 뿐 동일한 문제입니다
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

long double ret_len(pll a, pll b){
	ll dx = b.first - a.first;
	ll dy = b.second - a.second;
	long double N = (long double)(dx * dx + dy * dy);
	return sqrt(N);
}

ll CCW(pll p1, pll p2, pll p3){
	ll x1 = p1.first, x2 = p2.first, x3 = p3.first;
	ll y1 = p1.second, y2 = p2.second, y3 = p3.second;
	ll ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	return ccw;
}

int point_count, stack_size, next_point = 2, idx;
long double length_sum = 0.000000000000000000000000000;
long double PI = 3.14159265358979323846264338327;
long double LENGTH;
vector<pll> point_list;
vector<int> point_stack;

bool cmp(pll a, pll b){
	long long ccw = CCW(point_list[0], a, b);
	if (ccw != 0) {return ccw > 0;} // 각도가 작은 순서대로 넣음, 첫 번째 점과 두 점이 만드는 ccw 값이 0보다 크면 원하는 순서대로 정렬된 것이다 
	else {return a.first + a.second < b.first + b.second;} // 두 점이 각도가 같다면 가까운 점부터 정렬
}

int main(){
	int P1, P2;
	pll pp;
	scanf("%d %Lf", &point_count, &LENGTH);
	for (int p = 0; p < point_count; p++){
		scanf("%lld %lld", &pp.first, &pp.second);
		point_list.push_back(pp);
	}
	sort(point_list.begin(), point_list.end());
	sort(point_list.begin() + 1, point_list.end(), cmp);
	int idx;
	for (int i = 1; i < point_list.size(); i++){
		if (CCW(point_list[i - 1], point_list[i], point_list[0]) != 0){
			idx = i;
			break;
		}
	}
	sort(point_list.begin(), point_list.begin() + idx);
	for (int i = point_count - 1; i > 0; i--){
		if (CCW(point_list[i - 1], point_list[i], point_list[0]) != 0){
			idx = i;
			break;
		}
	}
	reverse(point_list.begin() + idx, point_list.end());
	point_stack.push_back(0);
	point_stack.push_back(1);
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
	}
	stack_size = point_stack.size();
	for (int i = 0; i < stack_size; i++){
		length_sum += ret_len(point_list[point_stack[i]], point_list[point_stack[(i + 1) % stack_size]]);
	}
	length_sum += 2.0000000000000000000000000000 * LENGTH * PI;
	printf("%.12Lf", length_sum);
}