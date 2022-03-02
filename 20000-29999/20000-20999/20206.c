// 20206 푸앙이가 길을 건너간 이유
// https://www.acmicpc.net/problem/20206
#include <stdio.h>
#include <stdbool.h>

long long int A, B, C, X1, X2, Y1, Y2;
long long int penetrate[4];
bool answer;

bool Penetrate_Square(){
	long long int count = 0, penetrate_count = 0;
	// 4개의 점을 모두 대입한다. 이후 대입한 값의 부호를 조사, 모두 같은 부호이거나, 부호가 없으면 지나지 않는다
	// 반대로 서로 다른 부호가 존재하면 관통하는 것이다.
	// printf("%lld %lld %lld %lld\n", A * X1 + B * Y1 + C, A * X1 + B * Y2 + C, A * X2 + B * Y1 + C, A * X2 + B * Y2 + C);
	penetrate[0] = A * X1 + B * Y1 + C;
	penetrate[1] = A * X1 + B * Y2 + C;
	penetrate[2] = A * X2 + B * Y1 + C;
	penetrate[3] = A * X2 + B * Y2 + C;
	if (A * X1 + B * Y1 + C < 0){penetrate[0] = -1;}
	else if (A * X1 + B * Y1 + C > 0){penetrate[0] = 1;}
	else {penetrate[0] = 0;}
	
	if (A * X1 + B * Y2 + C < 0){penetrate[1] = -1;}
	else if (A * X1 + B * Y2 + C > 0){penetrate[1] = 1;}
	else {penetrate[1] = 0;}
	
	if (A * X2 + B * Y1 + C < 0){penetrate[2] = -1;}
	else if (A * X2 + B * Y1 + C > 0){penetrate[2] = 1;}
	else {penetrate[2] = 0;}
	
	if (A * X2 + B * Y2 + C < 0){penetrate[3] = -1;}
	else if (A * X2 + B * Y2 + C > 0){penetrate[3] = 1;}
	else {penetrate[3] = 0;}
	
	for (int i = 0; i < 4; i++){
		if (penetrate[i] != 0){
			count++;
			penetrate_count += penetrate[i];
		}
	}
	return (count == penetrate_count || (count * (-1)) == penetrate_count);
}

int main(){
	scanf("%lld %lld %lld", &A, &B, &C);
	scanf("%lld %lld %lld %lld", &X1, &X2, &Y1, &Y2);
	answer = Penetrate_Square();
	if (!answer){printf("Poor");}
	else {printf("Lucky");}
	return 0;
}