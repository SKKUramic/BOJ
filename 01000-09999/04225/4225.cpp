// 4225 쓰레기 슈트
// https://www.acmicpc.net/problem/4225
// 점에서 변으로의 길이를 구하는 것이 아닌, 변에서 점으로의 길이를 구하니 풀렸음
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
long double answer_list[1000];

long double ret_len(pll a, pll b){
	ll dx = b.first - a.first;
	ll dy = b.second - a.second;
	ll N = dx * dx + dy * dy;
	return sqrt(N);
}

ll CCW(pll p1, pll p2, pll p3){
	ll x1 = p1.first, x2 = p2.first, x3 = p3.first;
	ll y1 = p1.second, y2 = p2.second, y3 = p3.second;
	ll ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
	return ccw;
}

long double ret_height(pll x, pll a, pll b){
	ll area = CCW(x, a, b);
	if (area < 0){area = -area;}
	long double len = ret_len(a, b);
	return ((long double) area) / len;
}

ll making_CCW(pll p1, pll p2, pll p3, pll p4){
	pll P1 = p1, P2 = p2;
	pll P3 = {p4.first - (p3.first - p2.first), p4.second - (p3.second - p2.second)};
	return CCW(P1, P2, P3);
}

int point_count, stack_size, idx, next_point = 2;
long double temp_len, temp1, temp2, MIN_LENGTH, TEMP_MAXLEN;
vector<pll> point_list;
vector<int> point_stack;

bool cmp(pll a, pll b){
	long long ccw = CCW(point_list[0], a, b);
	if (ccw != 0) {return ccw > 0;} // 각도가 작은 순서대로 넣음, 첫 번째 점과 두 점이 만드는 ccw 값이 0보다 크면 원하는 순서대로 정렬된 것이다 
	else {return a.first + a.second < b.first + b.second;} // 두 점이 각도가 같다면 가까운 점부터 정렬
}

int main(){
	int P1, P2, case_count = 1;
	pll pp;
	scanf("%d", &point_count);
	while (point_count != 0){
		MIN_LENGTH = 99999999999999.9999999;
		for (int p = 0; p < point_count; p++){
			scanf("%lld %lld", &pp.first, &pp.second);
			point_list.push_back(pp);
		}
		sort(point_list.begin(), point_list.end());
		sort(point_list.begin() + 1, point_list.end(), cmp);
		idx = point_list.size();
		for (int i = 1; i < point_list.size(); i++){
			if (CCW(point_list[i - 1], point_list[i], point_list[0]) != 0){
				idx = i;
				break;
			}
		}
		sort(point_list.begin(), point_list.begin() + idx);
		for (int i = point_count - 1; i > idx; i--){
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
		P1 = point_stack.back();
		point_stack.pop_back();
		P2 = point_stack.back();
		if (CCW(point_list[P2], point_list[P1], point_list[0]) > 0){
			point_stack.push_back(P1);
		}
		stack_size = point_stack.size();
		for (int j = 0; j < stack_size; j++){
			TEMP_MAXLEN = 0.000000000000000000000000000000;
			for (int i = 0; i < stack_size; i++){
				temp_len = ret_height(point_list[point_stack[i]], point_list[point_stack[j]], point_list[point_stack[(j + 1) % stack_size]]);
				if (TEMP_MAXLEN < temp_len){TEMP_MAXLEN = temp_len;}
			}
			if (TEMP_MAXLEN < MIN_LENGTH){MIN_LENGTH = TEMP_MAXLEN;}
		}
		MIN_LENGTH *= 100;
		if (MIN_LENGTH - (ll)MIN_LENGTH > 1e-12){
			MIN_LENGTH += 1;
			MIN_LENGTH = (ll) MIN_LENGTH;
		}
		MIN_LENGTH /= 100;
		answer_list[case_count] = MIN_LENGTH;
		case_count++;
		point_list.clear();
		point_stack.clear();
		next_point = 2;
		scanf("%d", &point_count);
	}
	for (int i = 1; i < case_count; i++){
		printf("Case %d: %.2Lf\n", i, answer_list[i]);
	}
}