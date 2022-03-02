// 3778 애너그램 거리
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int word1_alpha[26] = {0, };
int word2_alpha[26] = {0, };

int main(){
	char word1[50];
	char word2[50];
	int count = 0;
	int test, temp = 0, len1, len2;
	char c;
	cin >> test;
	cin.ignore();
	for (int i = 0; i < test; i++){
		while (1){
			//cin >> word1[temp];
			word1[temp] = getchar();
			//printf("!");
			if (word1[temp] == '\n'){
				word1[temp] = '\0';
				temp = 0;
				break;
			}
			temp++;
		}
		while (1){
			word2[temp] = getchar();
			//printf("?");
			if (word2[temp] == '\n'){
				word2[temp] = '\0';
				temp = 0;
				break;
			}
			temp++;
		}
		len1 = strlen(word1);
		len2 = strlen(word2);
		for (int i = 0; i < len1; i++){
			word1_alpha[word1[i] - 'a']++;
		}
		for (int i = 0; i < len2; i++){
			word2_alpha[word2[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++){
			count += abs(word1_alpha[i] - word2_alpha[i]);
			word1_alpha[i] = 0;
			word2_alpha[i] = 0;
		}
		printf("Case #%d: %d\n", i + 1, count);
		count = 0;
	}
}