// 11880 개미
// a와 b가 0일 수 있다는 조건이 없음
// https://www.acmicpc.net/problem/11880
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long int side[3];
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%lld %lld %lld", &side[0], &side[1], &side[2]);
		sort(side, side + 3);
		printf("%lld\n", (side[0] + side[1]) * (side[0] + side[1]) + side[2] * side[2]);
	}
}