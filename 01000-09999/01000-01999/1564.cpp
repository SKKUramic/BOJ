// 1564 팩토리얼5
// https://www.acmicpc.net/problem/1564
#include <iostream>
using namespace std;

int main(){
	long long N, answer = 1;
	cin >> N;
	for (long long n = 1; n <= N; n++){
		answer *= n;
		while (answer % 10 == 0){
			answer /= 10;
		}
		answer %= 1000000000000;
	}
	answer %= 100000;
	printf("%05lld", answer);
    return 0;
}