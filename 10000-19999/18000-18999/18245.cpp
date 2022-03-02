// 18245 이상한 나라의 암호
// https://www.acmicpc.net/problem/18245
#include <iostream>
#include <string>
using namespace std;

int main(){
	int slen, sentence_count = 1;
	string sentence;
	while (1){
		getline(cin, sentence);
		slen = sentence.size();
		if (sentence == "Was it a cat I saw?"){
			break;
		}
		for (int i = 0; i < slen; i += (sentence_count + 1)){
			cout << sentence[i];
		}
		cout << '\n';
		sentence_count++;
	}
}