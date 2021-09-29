// 1302 베스트셀러
// https://www.acmicpc.net/problem/1302
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> Book;
string list[1001];

int main(){
	int N, max = -1, idx = 0;
	string s, answer;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> s;
		if (Book.find(s) == Book.end()){
			Book[s] = 0;
			list[idx++] = s;
		}
		else {
			Book[s]++;
		}
	}
	for (int i = 0; i < idx; i++){
		s = list[i];
		if (Book[s] > max){
			answer = s;
			max = Book[s];
		}
		else if (Book[s] == max && s.compare(answer) < 0){
			answer = s;
			max = Book[s];
		}
	}
	cout << answer;
}