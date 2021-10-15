// 2553 마지막 팩토리얼 수
// https://www.acmicpc.net/problem/2553
#include <iostream>
using namespace std;

int main(){
	long long N, answer = 1;
	cin >> N;
	for (int n = 1; n <= N; n++){
		answer *= n;
		answer %= 100000000;
		while (answer % 10 == 0){
			answer /= 10;
		}
	}
	cout << answer % 10;
}