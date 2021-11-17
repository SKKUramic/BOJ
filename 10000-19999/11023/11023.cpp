// 11023 더하기 3
// https://www.acmicpc.net/problem/11023
#include <iostream>
using namespace std;

int main(){
	int N, sum = 0;
	while(1){
		cin >> N;
		if (cin.eof()){break;}
		sum += N;
	}
	cout << sum;
}