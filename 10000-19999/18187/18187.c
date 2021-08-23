// 18187 평면 분할
// https://www.acmicpc.net/problem/18187
#include <stdio.h>

int arr[101] = {0, };

int main(){
	int n = 1;
	int answer = 2, plus = 2, destination;
	int odd_flag = 0;
	scanf("%d", &destination);
	while (n != destination){
		if (plus % 2 == 0){
			answer += plus;
			plus++;
		}	
		else {
			if (odd_flag == 0){
				answer += plus;
				odd_flag = 1;
			}
			else if (odd_flag == 1){
				answer += plus;
				odd_flag = 0;
				plus++;
			}
		}
		n++;
	}
	printf("%d", answer);
}