// 18917 수열과 쿼리 38
// https://www.acmicpc.net/problem/18917
#include <iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long XOR = 0, SUM = 0, x;
	int command, M;
	cin >> M;
	while (M-- > 0){
		cin >> command;
		if (command == 1){
			cin >> x;
			SUM += x;
			XOR ^= x;
		}
		else if (command == 2){
			cin >> x;
			SUM -= x;
			XOR ^= x;
		}
		else if (command == 3){
			cout << SUM << '\n';
		}
		else if (command == 4){
			cout << XOR << '\n';
		}
	}
}