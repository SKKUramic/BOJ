// 1459 걷기
// https://www.acmicpc.net/problem/1459
#include <stdio.h>

typedef long long ll;

ll min(ll a, ll b){
	if (a < b) {return a;}
	else {return b;}
}

ll max(ll a, ll b){
	if (a > b) {return a;}
	else {return b;}
}

int main(){
	ll home_x, home_y, line_cost, diagonal_cost;
	scanf("%lld %lld %lld %lld", &home_x, &home_y, &line_cost, &diagonal_cost);
	if (line_cost * 2 <= diagonal_cost){
		printf("%lld", (home_x + home_y) * line_cost);
	}
	else {
		if (line_cost >= diagonal_cost){
			if ((home_x + home_y) % 2 == 0){
				printf("%lld", max(home_x, home_y) * diagonal_cost);
			}
			else {
				printf("%lld", (max(home_x, home_y) - 1) * diagonal_cost + line_cost);
			}
		}
		else {
			printf("%lld", min(home_x, home_y) * diagonal_cost + (home_x - min(home_x, home_y)) * line_cost + (home_y - min(home_x, home_y)) * line_cost);
		}
	}
}