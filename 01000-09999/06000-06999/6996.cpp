// 6996 애너그램
// https://www.acmicpc.net/problem/6996
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string word1, word2;
int word1_alpha[26], word2_alpha[26];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T-- > 0){
		for (int i = 0; i < 26; i++){
			word1_alpha[i] = 0;
			word2_alpha[i] = 0;
		}
		cin >> word1 >> word2;
		if (word1.length() != word2.length()){
			cout << word1 << " & " << word2 << " are NOT anagrams.\n";
			continue;
		}
		for (int i = 0; i < word1.length(); i++){
			word1_alpha[tolower(word1[i]) - 'a']++;
		}
		for (int i = 0; i < word2.length(); i++){
			word2_alpha[tolower(word2[i]) - 'a']++;
		}
		for (int k = 0; k < 26; k++){
			if (word1_alpha[k] != word2_alpha[k]){
				cout << word1 << " & " << word2 << " are NOT anagrams.\n";
				break;
			}
			if (k == 25){
				cout << word1 << " & " << word2 << " are anagrams.\n";
			}
		}
	}
}