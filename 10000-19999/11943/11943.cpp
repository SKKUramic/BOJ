// 11943 파일 옮기기
// https://www.acmicpc.net/problem/11943
#include <iostream>
using namespace std;

int main(){
	int apple_A, apple_B, orange_A, orange_B, answer;
	cin >> apple_A >> orange_A;
	cin >> apple_B >> orange_B;
	answer = min(apple_A + orange_B, orange_A + apple_B);
	cout << answer;
}