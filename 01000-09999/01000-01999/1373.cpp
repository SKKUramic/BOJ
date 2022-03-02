// 1373 2진수 8진수
// https://www.acmicpc.net/problem/1373
// 이게 맞네
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> eight;

int main(){
	int num = 0, count = 1;
	string two;
	cin >> two;
	for (int x = two.length() - 1; x >= 0; x--){
		num += count * (two[x] - '0');
		count *= 2;
		if (count == 8){
			eight.push_back(num);
			num = 0;
			count = 1;
		}
	}
	eight.push_back(num);
	for (int i = eight.size() - 1; i >= 0; i--){
		if (i == eight.size() - 1 && eight[i] == 0 && eight.size() != 1){continue;}
		else {cout << eight[i];}
	}
}