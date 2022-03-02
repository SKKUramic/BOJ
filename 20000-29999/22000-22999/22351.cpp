// 22351 수학은 체육과목 입니다 3
// https://www.acmicpc.net/problem/22351
#include <iostream>
#include <string>
using namespace std;

bool is_same_string(int start, int end, string S){
	string T = "";
	for (int x = start; x <= end && S.length() > T.length(); x++){
		T += to_string(x);
	}
	if (S.length() < T.length()){return false;}
	return S.compare(T) ? false : true;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string original;
	cin >> original;
	for (int i = 1; i < 1000; i++){
		for (int j = i; j < 1000; j++){
			if (is_same_string(i, j, original)){
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
}