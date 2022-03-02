// 5603 問題2
// https://www.acmicpc.net/problem/5603
// JOI 2006 본선 2번 문제입니다.
// 개미수열을 구현하는 문제이나, 원본은 (숫자)(숫자의 개수) 이지만 여기서는 (숫자의 개수)(숫자)의 형식으로 써야 합니다.
#include <stdio.h>
#include <string.h>

char ant_array[21][200000]; // 혹시 모르니 넉넉히 마련함
int ant_array_len[21];

int main(){
	int current_number = -1;
	int try, count, idx, temp;
	scanf("%d", &try);
	scanf("%s", ant_array[0]);
	for (int i = 0; i < try; i++){
		ant_array_len[i] = strlen(ant_array[i]);
		current_number = -1; count = 0; idx = 0;
		for (int k = 0; k < ant_array_len[i]; k++){
			if (current_number != ant_array[i][k] - '0'){ // 현재 검사하는 숫자와 기준 숫자가 서로 다를 때
				if (k != 0){ // 처음이 아닐 경우 ant_array에 저장
					while (count > 0){ // 높은 자릿수부터 저장해야 해서 별도로 만들었음
						temp = count;
						while (temp >= 10) {temp /= 10;}
						ant_array[i + 1][idx++] = temp + '0';
						count -= temp * 10;
					}
					if (count >= 0){ // count가 음수면 안 됨
						ant_array[i + 1][idx++] = count + '0';
					}
					ant_array[i + 1][idx++] = current_number + '0';
				}
				current_number = ant_array[i][k] - '0'; // 현재 가리키는 수를 저장, 이 숫자가 반복되는지 검사함
				count = 0; // 개수 초기화
			}
			count++;
		}
		ant_array[i + 1][idx++] = count + '0';
		ant_array[i + 1][idx++] = current_number + '0';
	}
	printf("%s", ant_array[try]);
}