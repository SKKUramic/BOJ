// 3059 등장하지 않는 문자의 합
// https://www.acmicpc.net/problem/3059
#include <iostream>
#include <string>
using namespace std;

bool alphabet[26];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string ALPHA;
	int T, sum;
	cin >> T;
	while (T-- > 0){
		for (int i = 0; i < 26; i++){
			alphabet[i] = false;
		}
		sum = 0;
		cin >> ALPHA;
		for (int i = 0; i < ALPHA.length(); i++){
			alphabet[ALPHA[i] - 'A'] = true;
		}
		for (int i = 0; i < 26; i++){
			if (alphabet[i] == false){
				sum += ('A' + i);
			}
		}
		cout << sum << '\n';
	}
}