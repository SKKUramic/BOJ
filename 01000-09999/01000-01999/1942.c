// 1942 디지털시계
// https://www.acmicpc.net/problem/1942
#include <stdio.h>

int Shour, Sminute, Ssecond, Ehour, Eminute, Esecond;

void nexttime(){
	Ssecond++;
	if (Ssecond >= 60){
		Ssecond = 0;
		Sminute++;
	}
	if (Sminute >= 60){
		Sminute = 0;
		Shour++;
	}
	if (Shour >= 24){Shour = 0;}
	return;
}

int main(){
	int num, answer;
	for (int i = 0; i < 3; i++){
		answer = 0;
		scanf("%d:%d:%d %d:%d:%d", &Shour, &Sminute, &Ssecond, &Ehour, &Eminute, &Esecond);
		while (Shour != Ehour || Sminute != Eminute || Ssecond != Esecond){
			num = Shour * 10000 + Sminute * 100 + Ssecond;
			if (num % 3 == 0){answer++;}
			nexttime();
		}
		num = Shour * 10000 + Sminute * 100 + Ssecond;
		if (num % 3 == 0){answer++;}
		printf("%d\n", answer);
	}
}