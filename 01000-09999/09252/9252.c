// 9252 LCS 2
// https://www.acmicpc.net/problem/9252
#include <stdio.h>
#include <string.h>

int LCS[1001][1001] = {0, };

char word1[1001], word2[1001], answer[1001];

int main(){
	int len1, len2, len_ans = 0;
	scanf("%s", word1);
	scanf("%s", word2);
	len1 = strlen(word1); len2 = strlen(word2);
	for (int i = 0; i <= len1; i++){
		for (int j = 0; j <= len2; j++){
			if (i == 0 || j == 0){
				LCS[i][j] = 0;
			}
			else if (word1[i - 1] == word2[j - 1]){
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
			}
		}
	}
	printf("%d\n", LCS[len1][len2]);
	while (LCS[len1][len2] != 0){
		if (LCS[len1][len2] == LCS[len1 - 1][len2]){
			len1--;
		}
		else if (LCS[len1][len2] == LCS[len1][len2 - 1]){
			len2--;
		}
		else {
			answer[len_ans++] = word1[len1 - 1];
			len1--;
			len2--;
		}
	}
	for (int i = len_ans - 1; i >= 0; i--){
		printf("%c", answer[i]);
	}
}