// 14626 ISBN
// https://www.acmicpc.net/problem/14626
#include <stdio.h>

int main(){
	int idx, sum = 0;
	char ISBN[15];
	scanf("%s", ISBN);
	for (int i = 0; i < 13; i++){
		if (ISBN[i] == '*'){idx = i;}
		else {sum += (ISBN[i] - '0') * (i % 2 == 0 ? 1 : 3);}
	}
	int answer = 0;
	while (1){
		if (idx % 2 == 0){
			if ((sum + answer) % 10 == 0){
				printf("%d", answer);
				break;
			}
		}
		else {
			if ((sum + answer * 3) % 10 == 0){
				printf("%d", answer);
				break;
			}
		}
		answer++;
	}
}