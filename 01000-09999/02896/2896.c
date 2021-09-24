// 2896 무알콜 칵테일
// https://www.acmicpc.net/problem/2896
#include <stdio.h>

int main(){
	double A, B, C, I, J, K;
	double ans1, ans2, ans3, ans;
	scanf("%lf %lf %lf", &A, &B, &C);
	scanf("%lf %lf %lf", &I, &J, &K);
	ans1 = A / I;
	ans2 = B / J;
	ans3 = C / K;
	if (ans1 < ans2){
		if (ans1 < ans3){
			ans = ans1;
		}
		else {
			ans = ans3;
		}
	}
	else {
		if (ans2 < ans3){
			ans = ans2;
		}
		else {
			ans = ans3;
		}
	}
	printf("%.6lf %.6lf %.6lf", A - ans * I, B - ans * J, C - ans * K);
}