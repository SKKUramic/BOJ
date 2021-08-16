// 1132 합
// https://www.acmicpc.net/problem/1132
#include <stdio.h>
#include <string.h>

int main(){
	long long alphabet[10] = {0, };
	char word[13];
	int used_first[10] = {0, };
	int N, len, max_idx;
	long long answer = 0, ten, max;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%s", word);
		used_first[word[0] - 'A'] = 1;
		len = strlen(word);
		ten = 1;
		while (len > 1){
			ten *= 10;
			len--;
		}
		len = strlen(word);
		for (int i = 0; i < len; i++){
			alphabet[word[i] - 'A'] += ten;
			ten /= 10;
		}
	}
	int used_alphabet = 0;
	for (int i = 0; i < 10; i++){
		if (alphabet[i] != 0){
			used_alphabet++;
		}
	}
	if (used_alphabet == 10){
		int not_first, min_idx;
		long long min = 999999999999999;
		for (int i = 0; i < 10; i++){
			if (used_first[i] == 0 && alphabet[i] < min){
				min = alphabet[i];
				min_idx = i;
			}
		}
		alphabet[min_idx] = 0;
		for (int i = 9; i >= 1; i--){
			max = -1;
			for (int k = 0; k < 10; k++){
				if (max < alphabet[k]){
					max = alphabet[k];
					max_idx = k;
				}
			}
			answer += max * i;
			alphabet[max_idx] = 0;
		}
	}
	else {
		for (int i = 9; i >= 0; i--){
			max = -1;
			for (int k = 0; k < 10; k++){
				if (max < alphabet[k]){
					max = alphabet[k];
					max_idx = k;
				}
			}
			answer += max * i;
			alphabet[max_idx] = 0;
		}	
	}
	printf("%lld", answer);
}