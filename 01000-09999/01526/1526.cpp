// 1526 가장 큰 금민수
// https://www.acmicpc.net/problem/1526
#include <iostream>
using namespace std;

bool fourseven(int N){
	while (N > 0){
		if (N % 10 != 4 && N % 10 != 7){return false;}
		N /= 10;
	}
	return true;
}

int main(){
	int N;
	cin >> N;
	while (N > 0){
		if (fourseven(N) == true){break;}
		N--;
	}
	cout << N;
}