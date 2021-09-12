// 1534 문서 검색
// https://www.acmicpc.net/problem/1543
#include <iostream>
#include <string>
using namespace std;

int main(){
	bool is_same;
	int count = 0, idx_count, word_len, search_len;
	string word, search;
	getline(cin, word);
	getline(cin, search);
	word_len = word.length();
	search_len = search.length();
	if (word_len < search_len){
		cout << 0;
		return 0;
	}
	for (int k = 0; k <= word_len - search_len; k++){
		is_same = true;
		for (int idx = 0; idx < search_len; idx++){
			if (search[idx] != word[idx + k]){
				is_same = false;
				break;
			}
		}
		if (is_same == true){
			count++;
			k += (search_len - 1);
		}
	}
	cout << count;
}