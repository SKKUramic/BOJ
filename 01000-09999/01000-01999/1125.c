// 1125 바닥 장식
// https://www.acmicpc.net/problem/1125
#include <stdio.h>

long long Treee[6] = {0, };
long long X1, X2, Y1, Y2;
long long tx1, tx2, ty1, ty2, answer = 0;

long long min(long long a, long long b){
	return a < b ? a : b;
}

void UDside(){
	if (ty1 % 10 == 0){ // 위
		Treee[ty1 - Y1] += (tx2 / 10) * 5 + (tx2 % 10 < 5 ? tx2 % 5 : 5);
		Treee[ty1 - Y1] -= (tx1 / 10) * 5 + (tx1 % 10 < 5 ? tx1 % 5 : 5);
		Treee[5] += (tx2 / 10) * (ty1 - Y1);
		Treee[5] -= (tx1 / 10) * (ty1 - Y1);
	}
	else {
		Treee[ty1 - Y1] += (tx2 / 10) * 5;
		Treee[ty1 - Y1] -= (tx1 / 10) * 5;
		Treee[5] += ((tx2 / 10) + (tx2 % 10 == 5)) * (ty1 - Y1);
		Treee[5] -= ((tx1 / 10) + (tx1 % 10 == 5)) * (ty1 - Y1);
	}
	if (ty2 % 10 == 0){ // 아래
		Treee[Y2 - ty2] += (tx2 / 10) * 5;
		Treee[Y2 - ty2] -= (tx1 / 10) * 5;
		Treee[5] += ((tx2 / 10) + (tx2 % 10 == 5)) * (Y2 - ty2);
		Treee[5] -= ((tx1 / 10) + (tx1 % 10 == 5)) * (Y2 - ty2);
	}
	else {
		Treee[Y2 - ty2] += (tx2 / 10) * 5 + (tx2 % 10 < 5 ? tx2 % 5 : 5);
		Treee[Y2 - ty2] -= (tx1 / 10) * 5 + (tx1 % 10 < 5 ? tx1 % 5 : 5);
		Treee[5] += (tx2 / 10) * (Y2 - ty2);
		Treee[5] -= (tx1 / 10) * (Y2 - ty2);
	}
	return;
}

void LRside(){
	if (tx1 % 10 == 0){ // 왼쪽 ???
		Treee[tx1 - X1] += (ty2 / 10) * 5;
		Treee[tx1 - X1] -= (ty1 / 10) * 5;
		Treee[5] += ((ty2 / 10) + (ty2 % 10 == 5)) * (tx1 - X1);
		Treee[5] -= ((ty1 / 10) + (ty1 % 10 == 5)) * (tx1 - X1);
		//printf("?%lld %lld\n", ((ty2 / 10) + (ty2 % 10 == 5)) * (tx1 - X1), ((ty1 / 10) + (ty1 % 10 == 5)) * (tx1 - X1));
	}
	else {
		Treee[tx1 - X1] += (ty2 / 10) * 5 + (ty2 % 10 < 5 ? ty2 % 5 : 5);
		Treee[tx1 - X1] -= (ty1 / 10) * 5 + (ty1 % 10 < 5 ? ty1 % 5 : 5);
		Treee[5] += (ty2 / 10) * (tx1 - X1);
		Treee[5] -= (ty1 / 10) * (tx1 - X1);
	}
	if (tx2 % 10 == 0){ // 오른쪽???
		Treee[X2 - tx2] += (ty2 / 10) * 5 + (ty2 % 10 < 5 ? ty2 % 5 : 5);
		Treee[X2 - tx2] -= (ty1 / 10) * 5 + (ty1 % 10 < 5 ? ty1 % 5 : 5);
		Treee[5] += (ty2 / 10) * (X2 - tx2);
		Treee[5] -= (ty1 / 10) * (X2 - tx2);
	}
	else { // ?
		Treee[X2 - tx2] += (ty2 / 10) * 5;
		Treee[X2 - tx2] -= (ty1 / 10) * 5;
		Treee[5] += ((ty2 / 10) + (ty2 % 10 == 5)) * (X2 - tx2);
		Treee[5] -= ((ty1 / 10) + (ty1 % 10 == 5)) * (X2 - tx2);
	}
	return;
}

void LCorner(){
	if (tx1 % 10 == 0){ 
		if (ty1 % 10 == 0){ // 왼쪽 위 대각선
			Treee[tx1 - X1] += (ty1 - Y1); // 가로
		}
		else {
			Treee[ty1 - Y1] += (tx1 - X1); // 세로
		}
		if (ty2 % 10 == 0){ // 왼쪽 아래 대각선
			Treee[Y2 - ty2] += (tx1 - X1); // 세로
		}
		else {
			Treee[tx1 - X1] += (Y2 - ty2); // 가로
		}
	}
	else { // 흠
		if (ty1 % 10 == 0){
			Treee[ty1 - Y1] += (tx1 - X1);
		}
		else {
			Treee[tx1 - X1] += (ty1 - Y1);
		}
		if (ty2 % 10 == 0){
			Treee[tx1 - X1] += (Y2 - ty2);
		}
		else {
			Treee[Y2 - ty2] += (tx1 - X1);
		}
	}
	return;
}

void RCorner(){
	if (tx2 % 10 == 0){ 
		if (ty1 % 10 == 0){ // 오른쪽 위
			Treee[ty1 - Y1] += (X2 - tx2); // 세로
		}
		else {
			Treee[X2 - tx2] += (ty1 - Y1); // 가로
		}
		if (ty2 % 10 == 0){ // 오른쪽 아래
			Treee[X2 - tx2] += (Y2 - ty2); // 가로
		}
		else {
			Treee[Y2 - ty2] += (X2 - tx2); // 세로
		}
	}
	else {
		if (ty1 % 10 == 0){
			Treee[X2 - tx2] += (ty1 - Y1); // 가로
		}
		else {
			Treee[ty1 - Y1] += (X2 - tx2); // 세로
		}
		if (ty2 % 10 == 0){
			Treee[Y2 - ty2] += (X2 - tx2); // 세로
		}
		else {
			Treee[X2 - tx2] += (Y2 - ty2); // 가로
		}
	}
	return;
}

void Calculate(){
	long long temp;
	answer += Treee[5]; Treee[5] = 0;
	
	temp = min(Treee[1], Treee[4]);
	answer += temp;
	Treee[1] -= temp; Treee[4] -= temp;
	temp = min(Treee[2], Treee[3]);
	answer += temp;
	Treee[2] -= temp; Treee[3] -= temp;
	temp = min(Treee[1] / 2, Treee[3]);
	answer += temp;
	Treee[1] -= temp * 2; Treee[3] -= temp;
	temp = min(Treee[1], Treee[2] / 2);
	answer += temp;
	Treee[1] -= temp; Treee[2] -= temp * 2;
	temp = min(Treee[1] / 3, Treee[2]);
	answer += temp;
	Treee[1] -= temp * 3; Treee[2] -= temp;
	answer += Treee[1] / 5;
	Treee[1] %= 5;
	
	answer += Treee[4];
	Treee[4] = 0;
	temp = min(Treee[3], Treee[1]);
	answer += temp;
	Treee[3] -= temp; Treee[1] -= temp;
	answer += Treee[2] / 2;
	Treee[2] %= 2;
	temp = min(Treee[2], Treee[1] / 2);
	answer += temp;
	Treee[2] -= temp; Treee[1] -= temp * 2;
	answer += Treee[1] / 4;
	Treee[1] %= 4;
	
	answer += Treee[3];
	Treee[3] = 0;
	temp = min(Treee[2], Treee[1]);
	answer += temp;
	Treee[2] -= temp; Treee[1] -= temp;
	answer += Treee[1] / 3;
	Treee[1] %= 3;
	
	answer += Treee[2];
	Treee[2] = 0;
	answer += Treee[1] / 2;
	Treee[1] %= 2;
	
	answer += Treee[1];
	Treee[1] = 0;
	return;
}

int main(){
	scanf("%lld %lld %lld %lld", &X1, &Y1, &X2, &Y2);
	
	tx1 = X1 + (X1 % 5 == 0 ? 0 : 5 - (X1 % 5)); // 왼쪽 세로선
	tx2 = X2 - X2 % 5; // 오른쪽 세로선
	ty1 = Y1 + (Y1 % 5 == 0 ? 0 : 5 - (Y1 % 5)); // 위쪽 가로선
	ty2 = Y2 - Y2 % 5; // 아래쪽 가로선
	if (tx1 > tx2 && ty1 > ty2){
		if ((X1 % 10 < 5) == (Y1 % 10 < 5)){ // 가로선 박스
			Treee[X2 - X1] = Y2 - Y1;
		}
		else {
			Treee[Y2 - Y1] = X2 - X1;
		}
	}
	else if (tx1 > tx2){ // 세로로 긴 직사각형
		if (tx2 % 10 == 0){
			Treee[5] += (ty2 / 10) * (X2 - X1);
			Treee[5] -= (ty1 / 10) * (X2 - X1);
			Treee[X2 - X1] += (ty2 / 10) * 5 + (ty2 % 10 == 5 ? 5 : 0);
			Treee[X2 - X1] -= (ty1 / 10) * 5 + (ty1 % 10 == 5 ? 5 : 0);
			if (ty1 % 10 != 0){Treee[X2 - X1] += ty1 - Y1;}
			else {Treee[ty1 - Y1] += X2 - X1;}
			if (ty2 % 10 != 0){Treee[Y2 - ty2] += X2 - X1;}
			else {Treee[X2 - X1] += Y2 - ty2;}
		}
		else {
			Treee[5] += ((ty2 / 10) + (ty2 % 10 == 5)) * (X2 - X1);
			Treee[5] -= ((ty1 / 10) + (ty1 % 10 == 5)) * (X2 - X1);
			Treee[X2 - X1] += (ty2 / 10) * 5;
			Treee[X2 - X1] -= (ty1 / 10) * 5;
			if (ty1 % 10 == 0){Treee[X2 - X1] += ty1 - Y1;}
			else {Treee[ty1 - Y1] += X2 - X1;}
			if (ty2 % 10 == 0){Treee[Y2 - ty2] += X2 - X1;}
			else {Treee[X2 - X1] += Y2 - ty2;}
		}
	}
	else if (ty1 > ty2){ // 가로로 긴 직사각형
		if (ty2 % 10 == 0){ // ?????
			Treee[5] += ((tx2 / 10) + (tx2 % 10 >= 5)) * (Y2 - Y1);
			Treee[5] -= ((tx1 / 10) + (tx1 % 10 >= 5)) * (Y2 - Y1);
			Treee[Y2 - Y1] += (tx2 / 10) * 5;
			Treee[Y2 - Y1] -= (tx1 / 10) * 5;
			if (tx1 % 10 == 0){Treee[Y2 - Y1] += tx1 - X1;}
			else {Treee[tx1 - X1] += Y2 - Y1;}
			if (tx2 % 10 == 0){Treee[X2 - tx2] += Y2 - Y1;}
			else {Treee[Y2 - Y1] += X2 - tx2;}
		}
		else { // ?
			Treee[5] += (tx2 / 10) * (Y2 - Y1);
			Treee[5] -= (tx1 / 10) * (Y2 - Y1);
			Treee[Y2 - Y1] += (tx2 / 10) * 5 + (tx2 % 10 == 5 ? 5 : 0);
			Treee[Y2 - Y1] -= (tx1 / 10) * 5 + (tx1 % 10 == 5 ? 5 : 0);
			if (tx1 % 10 == 0){Treee[tx1 - X1] += Y2 - Y1;}
			else {Treee[Y2 - Y1] += tx1 - X1;}
			if (tx2 % 10 == 0){Treee[Y2 - Y1] += X2 - tx2;}
			else {Treee[X2 - tx2] += Y2 - Y1;}
		}
	}
	else {
		Treee[5] += (tx2 - tx1) * (ty2 - ty1) / 5; // 사각형 내부
		UDside();
		LRside();
		LCorner();
		RCorner();
	}
	Calculate();
	printf("%lld", answer);
}