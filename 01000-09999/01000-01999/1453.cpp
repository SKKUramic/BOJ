// 1453 피시방 알바
// https://www.acmicpc.net/problem/1453
#include <iostream>
using namespace std;

bool seat[101];

int main(){
	int N, number, answer = 0;
	cin >> N;
	for (int n = 0; n < N; n++){
		cin >> number;
		if (seat[number]){answer++;}
		else {seat[number] = true;}
	}
	cout << answer;
}