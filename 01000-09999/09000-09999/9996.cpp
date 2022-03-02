// 9996 한국이 그리울 땐 서버에 접속하지
// https://www.acmicpc.net/problem/9996
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool valid;
	int File_N, slen, plen, limit;
	string pattern, s;
	cin >> File_N;
	cin >> pattern;
	plen = pattern.length();
	for (int i = 0; i < File_N; i++){
		cin >> s;
		valid = true;
		int pidx = 0;
		slen = s.length();
		for (int idx = 0; idx < slen; idx++){
			if (pattern[pidx] == '*'){
				limit = idx - 1;
				break;
			}
			else {
				if (pattern[pidx] != s[idx]){
					valid = false;
					break;
				}
				pidx++;
			}
		}
		pidx = plen - 1;
		for (int idx = slen - 1; idx > limit; idx--){
			if (pattern[pidx] == '*'){break;}
			else {
				if (pattern[pidx] != s[idx]){
					valid = false;
					break;
				}
				pidx--;
			}
		}
		if (valid == true && pattern[pidx] == '*'){cout << "DA\n";}
		else {cout << "NE\n";}
	}
}