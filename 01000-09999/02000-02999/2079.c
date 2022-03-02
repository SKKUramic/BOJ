// 2079 팰린드롬
// https://www.acmicpc.net/problem/2079
// 10942 팰린드롬? 문제의 해답 코드를 갖고 왔습니다.
// https://imnotabear.tistory.com/65(라이언납시오)의 풀이를 참조했습니다.
#include <stdio.h>
#include <string.h>

int Is_palindrome[2000][2000] = {0, }; // x번째 문자부터 i번째 문자까지의 문자열이 팰린드롬인지 저장
char palindrome[2001]; // 문자열 저장
int palindrome_string[2001] = {0, };

int main(){
	int len;
	scanf("%s", palindrome);
	len = strlen(palindrome);
	for (int idx = len; idx > 0; idx--){
		palindrome[idx] = palindrome[idx - 1];
	}
	palindrome[0] = ' '; // 혹시 몰라ㅎㅎ
	for (int i = 1; i <= len; i++){
		for (int k = 1; k <= i; k++){
			if (i - k == 0){ // 배열 길이가 1일 때 반드시 참
				Is_palindrome[k][i] = 1;
			}
			else if (i - k == 1){ // 배열 길이가 2일 때
				if (palindrome[i] == palindrome[k]){
					Is_palindrome[k][i] = 1;
				}
				else {
					Is_palindrome[k][i] = 0;
				}
			}
			else { // 배열 길이가 3 이상일 때
				if (Is_palindrome[k + 1][i - 1] == 1){
					if (palindrome[i] == palindrome[k]){
						Is_palindrome[k][i] = 1;
					}
					else {
						Is_palindrome[k][i] = 0;
					}
				}
				else {
					Is_palindrome[k][i] = 0;
				}
			}
		}
	}
	for (int i = 1; i <= len; i++){palindrome_string[i] = i;} // 문자열 길이 = 팰린드롬 개수라고 초기화 함
	for (int i = 1; i <= len; i++){
		for (int x = 1; x <= i; x++){
			if (Is_palindrome[x][i] == 1){ //x번째 문자부터 i번째 문자까지의 문자열이 팰린드롬일 때
				if (palindrome_string[i] > palindrome_string[x - 1] + 1){ // i번째까지의 문자열의 팰린드롬 개수보다 x-1번째까지의 문자열의 팰린드롬 개수+1이 더 작을 때
					palindrome_string[i] = palindrome_string[x - 1] + 1;
				}
			}
		}
	}
	printf("%d", palindrome_string[len]);
}