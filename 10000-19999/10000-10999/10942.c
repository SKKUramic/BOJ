// 10942 팰린드롬?
// https://www.acmicpc.net/problem/10942
#include <stdio.h>

int Is_palindrome[2001][2001] = {0, }; // 어디부터 어디까지의 정수열이 팰린드롬임? 뭐임?
int arr[2001];

int main(){
	int N, M, start, end;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
		for (int k = 1; k <= i; k++){
			if (i - k == 0){ // 배열 길이가 1일 때 반드시 참
				Is_palindrome[k][i] = 1;
			}
			else if (i - k == 1){ // 배열 길이가 2일 때
				if (arr[i] == arr[k]){
					Is_palindrome[k][i] = 1;
				}
				else {
					Is_palindrome[k][i] = 0;
				}
			}
			else { // 배열 길이가 3 이상일 때
				if (Is_palindrome[k + 1][i - 1] == 1){
					if (arr[i] == arr[k]){
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
			Is_palindrome[k][i];
		}
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++){
		scanf("%d %d", &start, &end);
		printf("%d\n", Is_palindrome[start][end]);
	}
}