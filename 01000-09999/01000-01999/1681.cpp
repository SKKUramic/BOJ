// 1681 줄 세우기
// https://www.acmicpc.net/problem/1681
#include <iostream>
using namespace std;

int N, hate;

bool ishate(int x){
	while (x > 0){
		if (x % 10 == hate){return false;}
		x /= 10;
	}
	return true;
}

int main(){
	int number = 1;
	int cnt = 0;
	cin >> N >> hate;
	while (cnt != N){
		if (ishate(number++) == true){
			cnt++;
		}
	}
	cout << number - 1;
}