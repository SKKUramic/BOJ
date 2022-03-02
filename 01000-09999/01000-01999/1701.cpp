// 1701 Cubeditor
// https://www.acmicpc.net/problem/1701
#include <iostream>
#include <string>
using namespace std;

int max_length = 0;

void Failure_function(const string &array){
	int start = 1, array_idx = 0;
	int len = array.length();
	int pi[5001] = {0, };
	while (start + array_idx < len){
		if (array[start + array_idx] == array[array_idx]){
			array_idx++;
			pi[start + array_idx - 1] = array_idx;
		}
		else {
			if (array_idx == 0){
				start++;
			}
			else {
				start += (array_idx - pi[array_idx - 1]);
				array_idx = pi[array_idx - 1];
			}
		}
	}
	for (int i = 0; i <= len; i++){ // 이상하게 pi를 전부 확인하는 게 아니면 WO가 뜨네요
		if (max_length < pi[i]){
			max_length = pi[i];
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string word;
	cin >> word;
	while (1){
		Failure_function(word);
		if (word.length() > 0){
			word = word.substr(1);
		}
		else {
			break;
		}
	}
	cout << max_length;
}