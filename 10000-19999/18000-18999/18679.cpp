// 18679 Banana
// https://www.acmicpc.net/problem/18679
#include <iostream>
#include <map>
using namespace std;

map<string, string> word_change;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string word_key, word_value, equality, sentence;
	int word, case_number;
	cin >> word;
	for (int i = 0; i < word; i++){
		cin >> word_key >> equality >> word_value;
		word_change[word_key] = word_value;
	}
	cin >> case_number;
	for (int i = 0; i < case_number; i++){
		cin >> word;
		for (int j = 0; j < word; j++){
			cin >> word_key;
			cout << word_change[word_key];
			if (j != word - 1){cout << ' ';}
		}
		cout << '\n';
	}
	return 0;
}