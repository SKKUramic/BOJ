// 1622 공통 순열
// https://www.acmicpc.net/problem/1622
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Aalpha[26], Balpha[26], idx;
	char alphabet;
	string A, B;
	while (1){
		getline(cin, A);
		if (cin.eof()){break;}
		getline(cin, B);
		for (int i = 0; i < 26; i++){
			Aalpha[i] = 0; Balpha[i] = 0;
		}
		for (int a = 0; a < A.length(); a++){
			Aalpha[A[a] - 'a']++;
		}
		for (int b = 0; b < B.length(); b++){
			Balpha[B[b] - 'a']++;
		}
		for (int i = 0; i < 26; i++){
			idx = Aalpha[i] < Balpha[i] ? Aalpha[i] : Balpha[i];
			alphabet = 'a' + i;
			for (int k = 0; k < idx; k++){cout << alphabet;}
		}
		cout << '\n';
	}
}