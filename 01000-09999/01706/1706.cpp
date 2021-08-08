// 1706 크로스워드
// https://www.acmicpc.net/problem/1706
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char crossword[20][20];
priority_queue<string, vector<string>, greater<string>> word_list;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> crossword[n][m];
		}
	}
	string word;
	word.clear();
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			if (crossword[n][m] == '#'){
				if (word.length() > 1){
					word_list.push(word);
				}
				word.clear();
			}
			else {
				word.push_back(crossword[n][m]);
			}
			if (m == M - 1){
				if (word.length() > 1){
					word_list.push(word);
				}
				word.clear();
			}
		}
		word.clear();
	}
	word.clear();
	for (int m = 0; m < M; m++){
		for (int n = 0; n < N; n++){
			if (crossword[n][m] == '#'){
				if (word.length() > 1){
					word_list.push(word);
				}
				word.clear();
			}
			else {
				word.push_back(crossword[n][m]);
			}
			if (n == N - 1){
				if (word.length() > 1){
					word_list.push(word);
				}
				word.clear();
			}
		}
		word.clear();
	}
	cout << word_list.top();
}