// 1509 팰린드롬 분할
// https://www.acmicpc.net/problem/1509
#include <stdio.h>
#include <string.h>

int DP[2501] = {0, };
char palindrome[2501], test[10];
bool is_palindrome[2501][2501];

int main(){
	palindrome[0] = '!'; // 더미값
	scanf("%s", palindrome + 1);
	int len = strlen(palindrome) - 1;
	for (int end = 1; end <= len; end++){
		for (int start = 1; start <= end; start++){
			if (end - start == 0){is_palindrome[start][end] = true;}
			else if (end - start == 1){
				if (palindrome[start] == palindrome[end]){
					is_palindrome[start][end] = true;
				}
			}
			else {
				if (palindrome[start] == palindrome[end] && is_palindrome[start + 1][end - 1] == true){
					is_palindrome[start][end] = true;
				}
			}
		}
	}
	for (int i = 0; i <= 2500; i++){DP[i] = -1;}
	DP[0] = 0; DP[1] = 1; // DP[0]은 기저값, DP[1]은 무조건 1임
	for (int end = 1; end <= len; end++){
		for (int start = 1; start <= end; start++){
			if (is_palindrome[start][end] == true){ // start부터 end까지의 문자열이 회문일 때
				if (DP[end] == -1 || DP[end] > DP[start - 1] + 1){ // 아직 end까지의 문자열에 회문이 없었거나, (start 이전까지의 회문 개수) + 1이 (end까지의 회문 개수)보다 적을 경우
					DP[end] = DP[start - 1] + 1;
				}
			}
		}
	}
	printf("%d", DP[len]);
}