// 16478 원의 분할
// https://www.acmicpc.net/problem/16478
// 원의 두 현과 그 교점이 있을 때 사용하는 공식을 이용하면 됩니다.
#include <stdio.h>

int main(){
	double Pab, Pbc, Pcd;
	scanf("%lf %lf %lf", &Pab, &Pbc, &Pcd);
	printf("%.7lf", (Pab * Pcd) / Pbc);
}