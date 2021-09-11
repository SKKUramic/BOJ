// 1062 가르침
// https://www.acmicpc.net/problem/1062
#include <stdio.h>
#include <string.h>

int len, N, K, answer = 0;
int word_alphabet[51] = {0, };
char word[16];

void nCm(int used_alphabet, int word_comb, int idx){
	if (used_alphabet == K){
		int count = 0;
		for (int n = 0; n < N; n++){
			if ((word_comb & word_alphabet[n]) == word_alphabet[n]){
				count++;
			}
		}
		if (count > answer){answer = count;}
		return;
    }
    for (int i = idx + 1; i < 26; i++){
		nCm(used_alphabet + 1, word_comb | (1 << i), i);
    }
	return;
}

int main(){
    scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++){
		scanf("%s", word);
		len = strlen(word);
		for (int i = 0; i < len; i++){
			word_alphabet[n] |= (1 << (word[i] - 'a'));
		}
	}
	for (int i = 0; i < 26; i++){
		nCm(1, 1 << i, i);
    }
	printf("%d", answer);
	return 0;
}
