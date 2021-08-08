// 16171 나는 친구가 적다 (Small)
// https://www.acmicpc.net/problem/16171
// KMP 알고리즘따위 안 써도 됨
#include <stdio.h>
#include <string.h>

int main(){
	char write[101];
	char find[101];
	int write_len, find_len, find_idx = 0, did_you_find = -1;
	scanf("%s", write);
	scanf("%s", find);
	write_len = strlen(write);
	find_len = strlen(find);
	for (int start = 0; start < write_len; start++){
		for (int idx = start; idx < write_len; idx++){
			if (write[idx] < '0' || write[idx] > '9'){ // 영어일 경우
				if (write[idx] == find[find_idx]){
					find_idx++;
				}
				else { // 영어인데 다르면 안 되는데?
					find_idx = 0;
					break;
				}
				if (find_idx == find_len){
					did_you_find = 1;
					break;
				}
			} // 숫자일 경우는 아무것도 안 해도 됨
		}
	}
	if (did_you_find == 1){
		printf("1");
	}
	else {
		printf("0");
	}
}