// 2407 조합
// https://www.acmicpc.net/problem/2407
// 꾸준함 님의 블로그 https://jaimemin.tistory.com/682에서 수열 덧셈 함수를 참조했습니다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string pascal[501][501];

string number_plus(string A, string B){
	int sum = 0;
    string answer = "";
	while (A.size() != 0 || B.size() != 0 || sum != 0){
		if (A.size() != 0){
			sum += A.back() - '0';
			A.pop_back();
		}
		if (B.size() != 0){
			sum += B.back() - '0';
			B.pop_back();
		}
		answer.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

void making_triangle(int n){
	pascal[0][0] = "1";
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i){
				pascal[i][j] = "1";
			}
			else {
				pascal[i][j] = number_plus(pascal[i - 1][j], pascal[i - 1][j - 1]);
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	making_triangle(n);
	cout << pascal[n][m];
	return 0;
}